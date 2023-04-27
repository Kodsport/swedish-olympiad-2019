import sys

sys.setrecursionlimit(1000000)

#indata
N = int(sys.stdin.readline())
M = []
E = [[] for i in range(N)]
for i in range(N):
    temp = [j for j in map(int,sys.stdin.readline().split())]
    M.append(temp[0])
    for j in range(2,2+2*temp[1],2):
        E[temp[j]-1].append([i,temp[j+1]])

def prod(v):
    if not E[v]:
        return M[v]
    else:
        val = 0.0
        for u in E[v]:
            val += prod(u[0])*u[1]/100.0
        return min(M[v],val)

ans = []
for i in range(N):
    if prod(i) == M[i]:
        ans.append(i)

#output
ans.sort()
output = ""
for node in ans:
    output += str(node+1)+" "
print(output)
