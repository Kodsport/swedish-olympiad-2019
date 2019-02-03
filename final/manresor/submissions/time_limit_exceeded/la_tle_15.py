from itertools import product
import sys
sys.setrecursionlimit(2*10**5)

def valid(tickets):
    covered = set()
    for i in range(len(tickets)):
        if tickets[i] == -1: continue
        for j in range(i+1,i+1+g[tickets[i]]): 
            covered.add(j)
    for day in d:
        if day not in covered: return False
    return True

def cost(tickets):
    cst = 0
    for day,ticket in enumerate(tickets):
        if ticket == -1: continue
        if day+1 in r: cst += p[ticket]/2
        else: cst += p[ticket]
    return cst

INF = 10**20
N,M,K = map(int,raw_input().split())
d = map(int,raw_input().split())
g = map(int,raw_input().split())
p = map(int,raw_input().split())
r = set(map(int,raw_input().split()))
b = [(g[i],p[i]) for i in range(M)]
possible_tickets = [-1] + list(range(M))
minimal_cost = INF
for x in product(possible_tickets,repeat=d[-1]):
    if valid(x):
        minimal_cost = min(cost(x),minimal_cost)
print minimal_cost
