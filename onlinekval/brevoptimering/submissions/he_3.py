import sys

sys.setrecursionlimit(1000000)

#indata
N = int(sys.stdin.readline())
M = []
E = [[] for i in range(N)]
C = [-1]*N
for i in range(N):
    temp = [j for j in map(int,sys.stdin.readline().split())]
    M.append(temp[0])
    for j in range(2,2+2*temp[1],2):
        E[temp[j]-1].append([i,temp[j+1]])

def prod(v):
    if C[v] != -1:
        return C[v]
    if not E[v]:
        C[v] = M[v]
    else:
        C[v] = min(M[v],prod(E[v][0][0])*E[v][0][1]/100.0)
    return C[v]

ans = []
for i in range(N):
    if (prod(i) == M[i]):
        ans.append(i)

#output
ans.sort()
output = ""
for node in ans:
    output += str(node+1)+" "
print output