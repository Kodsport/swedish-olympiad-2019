#!/usr/bin/env python3
# Entirely random grid, with # occurring with probability 'fireRatio'.

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
fireRatio = float(cmdlinearg('fireRatio'))

grid = [
    [('#' if random.uniform(0,1) < fireRatio else '.') for _ in range(c)]
    for _ in range(r)
]

grid[0][0] = '.'
grid[r-1][c-1] = '.'

print(r, c, k)
for row in grid:
    print(''.join(row))
