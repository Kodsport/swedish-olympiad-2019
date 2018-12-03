import sys

sys.setrecursionlimit(1000000)

#indata
N = int(sys.stdin.readline())
M = []
E = []
C = [-1]*N
nodes = []
vis = [0]*N
for i in range(N):
    temp = [j for j in map(int,sys.stdin.readline().split())]
    M.append(temp[0])
    E.append([])
    for j in range(2,2+2*temp[1],2):
        temp[j] -= 1
        E[i].append(temp[j:j+2])


#toposort:
def dfs(v):
    for u in E[v]:
        if not vis[u[0]]:
            vis[u[0]] = 1
            dfs(u[0])
    nodes.append(v)

for i in range(N):
    if not vis[i]:
        vis[i] = 1
        dfs(i)
nodes.reverse()

#simulering
ans = []
for v in nodes:
    if C[v] == -1 or C[v] >= M[v]:
        C[v] = M[v]
        ans.append(v)
    for u in E[v]:
        if C[v]==-1:
            C[v] = 0
        C[u[0]] += C[v]*u[1]/100.0

#output
ans.sort()
output = ""
for node in ans:
    output += str(node+1)+" "
print output