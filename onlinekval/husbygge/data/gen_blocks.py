#!/usr/bin/env python3

from common import *

blocks = int(cmdlinearg('blocks'))

grid = [[1]*m for _ in range(n)]
for i in range(blocks):
    if i < 3:
        s = [n//4, n//5, n//6][i]
    else:
        s = 10
    y = random.randint(0, n - s)
    x = random.randint(0, m - s)
    for j in range(s):
        for k in range(s):
            grid[y + j][x + k] = 0

print(n, m, k)
for i in range(n):
    print(*grid[i])
