#!/usr/bin/env python3
#Generate testcases for group 3, every column consist of a fire pillar from the top and a fire pillar from the bottom.

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
r = int(cmdlinearg('r'))
c = int(cmdlinearg('c'))
k = int(cmdlinearg('k'))
mode = cmdlinearg('mode')
assert mode in ['assureFreePath', 'random']
assureFreePath = (mode == 'assureFreePath')

grid = [['#'] * c for j in range(r)]

x1 = r//2
lastXL = r

sqrtr = round(r**0.5)

for y in range(c):
    xL = 0
    if assureFreePath: #Place pillars so that it is always possible to go from one column to the next without going through fires
        xL = random.randint(sqrtr, r-1) * random.randint(sqrtr, r-1) // (r-1)
        xL = max(xL, 1)
        x1 = random.randint(x1-xL+1, x1+lastXL-1)
        x1 = max(0,x1)
        x1 = min(x1,r-xL)
    else: #Place pillars randomly, prefering shorter gaps than longer gaps
        xL = random.randint(1, r) * random.randint(1, r) // r
        xL = max(xL, 1)
        x1 = random.randint(0, r-xL)
    x2 = x1 + xL
    if y == 0:
        x1 = 0
    if y == c-1:
        x2 = r
    for x in range(x1, x2):
        grid[x][y] = '.'
    lastXL = xL

if assureFreePath:
    for i in range(r):
        for j in [0, c-1]:
            grid[i][j] = '.'

print(r, c, k)
for row in grid:
    print(''.join(row))
