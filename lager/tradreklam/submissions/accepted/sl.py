#!/usr/bin/env python3
import sys

sys.setrecursionlimit(10000)

N, B = map(int, input().split())
pop = [0] + [int(x) for x in input().split()]
ed = [[] for _ in range(N)]

for _ in range(N - 1):
    a, b, c = map(int, input().split())
    a -= 1
    b -= 1
    ed[a].append((b, c))
    ed[b].append((a, c))

dp = [0] * (B + 1)

def rec(at, par, parcost):
    cover = pop[at]
    cp = list(dp)
    for a, b in ed[at]:
        if a != par:
            cover += rec(a, at, b)
    for b in range(B + 1):
        if b + parcost <= B:
            dp[b + parcost] = max(dp[b + parcost], cp[b] + cover)
    return cover

rec(0, -1, B+1)

print(max(dp))
