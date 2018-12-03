#!/usr/bin/env python3
# Starting with a grid full of #, generate random axis-aligned lines of . until there is a solution

import sys
import random
import helpers

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

seed = int(cmdlinearg('seed', sys.argv[-1]))
r = int(cmdlinearg('r'))
c = int(cmdlinearg('c'))
k = int(cmdlinearg('k'))

def getGrid(paths):
    random.seed(seed)
    grid = [['#'] * c for j in range(r)]
    grid[0][0] = '.'
    grid[r-1][c-1] = '.'
    for x in range(r//2,r):
        grid[x][c-1] = '.'
    for y in range(c//2,c):
        grid[r-1][y] = '.'
    for i in range(paths):
        if random.randint(0,1) == 1: #vertical path
            x = random.randrange(r)
            yL = random.randrange(c // 2)
            y1 = random.randrange(c - yL + 1)
            for y in range(y1,y1 + yL):
                grid[x][y] = '.'
        else: # horizontal path
            y = random.randrange(c)
            xL = random.randrange(r//2)
            x1 = random.randrange(r - xL + 1)
            for x in range(x1, x1 + xL):
                grid[x][y] = '.'

    return grid

dn = 0
up = r+c

while dn+1<up:
    mid = (dn+up)//2;
    if helpers.solve(getGrid(mid),k) == -1:
        dn = mid
    else:
        up = mid

grid = getGrid(up);

print(r, c, k)
for row in grid:
    print(''.join(row))
