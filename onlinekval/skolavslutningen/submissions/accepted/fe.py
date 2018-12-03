#!/usr/bin/env python3
import sys
sys.setrecursionlimit(1000000000)

inp = input()
n = int(inp.split()[0])
m = int(inp.split()[1])
k = int(inp.split()[2])

e = [[] for i in range(k)]
seen = [False for i in range(k)]

def dfs(v, d):
	#print(d,v)
	if seen[v]==True:
		return
	seen[v] = True
	for u in e[v]:
		dfs(u, d+1)

grid = [];
for i in range(n):
	row = input()
	grid.append(row)

for i in range(n-1):
	for j in range(m):
		e[ord(grid[i][j])-ord('A')].append(ord(grid[i+1][j])-ord('A'));
		e[ord(grid[i+1][j])-ord('A')].append(ord(grid[i][j])-ord('A'));


numComp = 0;
for i in range(k):
	if seen[i]==False:
		numComp += 1
		dfs(i,0)

print(numComp)
