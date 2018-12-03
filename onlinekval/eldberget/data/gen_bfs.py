#!/usr/bin/env python3
# A grid which consists of almost only #, but with a (sometimes broken) path of . walking from start to end.
# The path avoids passing within 'radius' of itself. If it self-intersects, it skips outputting . for a bit.
# k should generally be set low (~radius).

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
assert mode in ['normal', 'rightDown']
right_down = (mode == 'rightDown')

radius = int(cmdlinearg('radius')) # Minimum distance between two paths

grid = [['#'] * c for j in range(r)]

q = [(0,0,-1),(r-1,c-1,-1)]

while len(q)>0:
    x=0
    y=0
    d=0
    (x,y,d) = q[0]
    q.pop(0)

    if x<0 or y<0 or x>=r or y>=c:
        continue
    if grid[x][y] == '.':
        continue

    numClose = 0

    x1 = max(0,x-radius)
    x2 = min(r,x+radius+1)
    y1 = max(0,y-radius)
    y2 = min(c,y+radius+1)
    if d==0:
        y2 = y+1
    if d==1:
        x1 = x
    if d==2:
        y1 = y    
    if d==3:
        x2 = x+1

    for i in range(x1,x2):
        for j in range(y1,y2):
            if grid[i][j] == '.':
                numClose += 1

    if numClose>0:
        continue

    toPush = [(x,y+1,2),(x+1,y,1)]
    if not right_down:
        toPush += [(x,y-1,0),(x-1,y,3)]
    random.shuffle(toPush)

    for t in toPush:
        q.insert(0,t);

    grid[x][y] = '.'

# Add a few extra fires, to make the value of k more relevant
empty = [(i,j) for i in range(r) for j in range(c) if grid[i][j] == '.']
for pos in random.sample(empty, min(k, len(empty) // 2)):
    grid[pos[0]][pos[1]] = '#'

grid[0][0] = '.'
grid[r-1][c-1] = '.'

print(r, c, k)
for row in grid:
    print(''.join(row))
