#!/usr/bin/env python3

import sys
import random


def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default


random.seed(int(cmdlinearg("seed", sys.argv[-1])))
n, m = random.randint(2, 20), random.randint(2, 20)
k = random.randint(1, 30)
if int(cmdlinearg("no_right_wall", 0)):
    k = min(k, m)
if int(cmdlinearg("n_is", 0)):
    n = 2

g = [[-1] * m for _ in range(n)]

r = 0
c = 0
dr = 1
dc = 1
am = 0
for _ in range(n * m):
    if g[r][c] == -1:
        g[r][c] = am
        am += 1

    r += dr
    c += dc

    if r < 0:
        r = 1
        dr = 1
    if c < 0:
        c = 1
        dc = 1
    if r >= n:
        r = n - 2
        dr = -1
    if c >= m:
        c = m - 2
        dc = -1

k = min(k, am)

print(n, m)
print("".join([random.choice("QWERTYUIOPASDFGHJKLZXCVBNM") for _ in range(k)]))
