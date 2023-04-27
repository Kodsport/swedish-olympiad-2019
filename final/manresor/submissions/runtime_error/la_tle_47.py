import sys
sys.setrecursionlimit(2*10**5)

def get_smallest_price(distance):
    hi = M-1 #possible
    lo = -1 #impossible
    while hi - lo > 1:
        mid = (hi+lo)//2
        if g[mid] >= distance: hi = mid
        else: lo = mid
    return p[hi]

INF = 10**20
N,M,K = map(int,input().split())
d = list(map(int,input().split()))
g = list(map(int,input().split()))
p = list(map(int,input().split()))
r = list(map(int,input().split()))

prev_discount = []
if r:
    for day in d:
        if r[0] > day: 
            prev_discount.append(None)
            continue
        lo = 0 #possible
        hi = K #impossible
        while hi - lo > 1:
            mid = (hi+lo)//2
            if r[mid] > day: hi = mid
            else: lo = mid
        prev_discount.append(r[lo])

#cost[from][to] = cost for taking trips from,...,to (inclusive)
cost = [[-1]*N for _ in range(N)]
for i in range(N): cost[i][i] = p[0]
for i in range(N):
    if r and prev_discount[i] != None and d[i]-prev_discount[i]+1 <= g[-1]:
        cost[i][i] = min(cost[i][i],get_smallest_price(d[i]-prev_discount[i]+1)/2)

for diff in range(1,N):
    for fr in range(N-diff):
        to = fr+diff
        min_cost = INF
        if d[to]-d[fr]+1 <= g[-1]: 
            min_cost = get_smallest_price(d[to]-d[fr]+1)
        if r and prev_discount[fr] != None and d[to]-prev_discount[fr]+1 <= g[-1]:
            min_cost = min(min_cost,get_smallest_price(d[to]-prev_discount[fr]+1)/2)
        for mid in range(fr,to):
            min_cost = min(min_cost,cost[fr][mid]+cost[mid+1][to])
        cost[fr][to] = min_cost

print cost[0][N-1]
