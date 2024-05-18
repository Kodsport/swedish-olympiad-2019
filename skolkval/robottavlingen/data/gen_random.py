#!/usr/bin/env python3

import sys
import random as rnd


def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default


rnd.seed(int(cmdlinearg("seed", sys.argv[-1])))

lo: int = int(cmdlinearg("lo", 3))
hi: int = int(cmdlinearg("hi", 10))

n: int = rnd.randint(lo, hi)
MAX_HEIGHT: int = 5

grid = [[rnd.randint(1, MAX_HEIGHT) for _ in range(n)] for _ in range(n)]

rows = [min(row) for row in grid]
cols = [min((grid[j][i] for j in range(n))) for i in range(n)]

print(n)
print(*rows)
print(*cols)
