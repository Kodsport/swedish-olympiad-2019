import sys

with open(sys.argv[1]) as f:
    t = int(f.readline())
    n, m, k = map(int, f.readline().split())
    board = [None] * n
    for i in range(n):
        board[i] = list(map(int, f.readline().split()))

marked = [[False] * m for _ in range(n)]

for i in range(k):
    r, c = map(int, input().split())
    r -= 1
    c -= 1
    marked[r][c] = True

for i in range(n):
    out = []
    for j in range(m):
        v = min(board[i][j], 99)
        s = str(v // 10)
        if marked[i][j]:
            s = '\033[31m{}\033[39m'.format(s) # red
        out.append(s)
    print(''.join(out))
