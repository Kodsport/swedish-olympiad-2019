#!/usr/bin/env python3
inp = list(map(int, input().split()))

n = inp[0]
m = inp[1]
k = inp[2]


meals = [(0,0) for i in range(m)]

choices = list(map(int, input().split()))

for meal in choices:
    meals[meal-1] = (0,meals[meal-1][1]+1)

costIn = list(map(int, input().split()))
for i,cost in enumerate(costIn):
    meals[i] = (cost,meals[i][1])

meals.sort()
meals.reverse()

freeMeals = []

swaps = []

for i in range(m):
    p = meals[i][1]
    c = meals[i][0]
    if p == 0:
        freeMeals.append(c)
    else:
        k -= 1
    while len(freeMeals)>0 and p>1:
        swaps.append(freeMeals.pop()-c)
        p -= 1

stuff = []
for i in range(m):
	stuff.append(i)
for i in range(m):
	stuff.pop()
	

if len(swaps) < k:
    print(-1)
else:
    swaps.sort()

    ans = 0;

    for i in range(k):
        ans+=swaps[i]
    print(ans)