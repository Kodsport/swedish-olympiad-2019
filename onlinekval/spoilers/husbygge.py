def neighs(d):
    for x in range(-d, d+1):
        for y in range(-d, d+1):
            if abs(x) + abs(y) <= d:
                yield x, y

def ok(i, j):
    return 0 <= i < N and 0 <= j < M

def filt(d, i, j):
    n = filter(lambda x: ok(x[0] + i, x[1] + j), neighs(d))
    v = [[] for _ in range(d+1)]
    for x, y in n:
        v[abs(x) + abs(y)].append((i+x, j+y))
    return v



invalid = set()
def default_sol(board, K, cover=lambda x: 10):
    N, M = len(board), len(board[0])
    ps = []
    for i in range(N):
        for j in range(M):
            ps.append((board[i][j], i, j))
    ps.sort()
    out = []
    used = set()

    for sc, i, j in ps[::-1]:
        if len(out) == K: break
        if (i, j) in invalid: continue
        invalid.add((i, j))
        used.add((i, j))
        out.append('{} {}'.format(i+1, j+1))
        left = N*M - len(invalid)
        rms = filt(cover(len(out)), i, j)
        SM = 0
        i2 = 0
        for i2, l in enumerate(rms[1:]):
            if set(l)&used:
                break
            SM += len(l)
            if left - SM < (K - len(out)):
                break
        
        for l in rms[1:i2+1]:
            for x, y in l:
                invalid.add((x, y))
    print('\n'.join(out))


def sol_1(board, K):
    def gen(no1, no2):
        out = []
        pos = [[True]*M for _ in range(N)]
        for i in range(N):
            for j in range(M):
                if pos[i][j] and board[i][j]:
                    if len(out) == K:
                        out.pop()
                    out.append('{} {}'.format(i+1, j+1))
                    for x, y in neighs(no1 + int(len(out) < no2)):
                        if ok(i+x, j + y):
                            pos[i+x][j+y] = False
        if len(out) == K:
            return '\n'.join(out)
        else: return None

    lo, hi = 0, N+M
    while lo < hi:
        mid = (lo + hi + 1) >> 1
        r = gen(mid, 0)
        if r:
            lo = mid
        else:
            hi = mid - 1
    no1 = lo

    lo, hi = 0, K
    while lo < hi:
        mid = (lo + hi+1)/2
        r = gen(no1, mid)
        if r:
            lo = mid
        else:
            hi = mid - 1
    print(gen(no1, lo))

def sol_3(board, K):
    DP = [(-1, (-1, -1))]*(K+1)*(201*201)
    def compr(k, i, dx):
        return k*201*201 + i*201 + dx
    INF = 10**10
    def calc(k, i, dx):
        if k == 1: return board[i-1][0]*dx
        if i < 0: return -INF
        c = compr(k, i, dx)
        if DP[c][0] != -1:
            return DP[c][0]
        MAX = (-INF, (-1, -1))
        v = board[i-1][0]
        for j in range(1, i):
            MAX = max(MAX, (v*min(dx, i-j) + calc(k-1, j, i-j), (j, i-j)))
        DP[c] = MAX
        return MAX[0]

    M = (-1, (-1, -1))
    for i in range(1, N+1):
        for j in range(1, N+1):
            M = max(M, (calc(K, i, j), (i, j)))
    out = []
    while K:
        out.append(M[1][0])
        M = DP[compr(K, M[1][0], M[1][1])]
        K -= 1
    print('\n'.join(map(lambda x: '{} 1'.format(x), out)))

def sol_5(board, K):
    def gen(no1, start):
        out = []
        pos = [[True]*M for _ in range(N)]
        S = 0
        for i in range(N-1, start-1, -1):
            for j in range(M):
                if pos[i][j] and board[i][j]:
                    if len(out) == K:
                        break
                    S += board[i][j]
                    out.append((i, j))
                    for x, y in neighs(no1):
                        if ok(i+x, j + y):
                            pos[i+x][j+y] = False
        
        if len(out) == K:
            return S*no1, '\n'.join(map(lambda x: '{} {}'.format(x[0]+1, x[1]+1), out))
        else: return None

    def get_v(start):
        lo, hi = 0, N+M
        while lo < hi:
            mid = (lo + hi + 1) >> 1
            r = gen(mid, start)
            if r:
                lo = mid
            else:
                hi = mid - 1
        r = gen(lo, start)
        return r
    
    MAX = (0, "")
    v = 100 if K < 100 else 1
    for s in range(0, v):
        r = get_v(s)
        if r:
            MAX = max(MAX, r)
    print MAX[1]

        


T = input()
N, M, K = map(int, raw_input().split())
board = [map(int, raw_input().split()) for _ in range(N)]

from collections import defaultdict

c1 = int((N*M/K)**.5)
c2 = int((N*M/K)**.5) + 1
L1 = lambda x: c2 
C = defaultdict(lambda : L1)
C[3] = lambda x: c2 + 1
C[4] = lambda x: c1
C[5] = lambda x: c2+1
C[6] = lambda x: c1
C[7] = lambda x: int(c1*1.5 - x*1.0*c1/K)
C[8] = lambda x: 14
C[9] = lambda x: 14

if T == 1 or T == 10:
    sol_1(board, K)
elif T == 3:
    sol_3(board, K)
elif T == 5 or T==6:
    sol_5(board, K)
else:
    default_sol(board, K, C[T])
