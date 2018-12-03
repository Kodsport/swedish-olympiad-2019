import sys

#indata
N = int(sys.stdin.readline())
M = []
E = []
C = [0.0]*N
for i in range(N):
    temp = [j for j in map(int,sys.stdin.readline().split())]
    M.append(temp[0])
    E.append([])
    for j in range(2,2+2*temp[1],2):
        temp[j] -= 1
        E[i].append(temp[j:j+2])

#simulering
ans = []
for v in range(N):
    if C[v] == 0 or C[v] >= M[v]:
        C[v] = M[v]
        ans.append(v)
    for u in E[v]:
        C[u[0]] += C[v]*u[1]/100.0

#output
ans.sort()
output = ""
for node in ans:
    output += str(node+1)+" "
print output
