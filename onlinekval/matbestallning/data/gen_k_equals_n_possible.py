#!/usr/bin/env python3
#First placing one of each type, then randomizing the rest.

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n'))
m = int(cmdlinearg('m'))
k = n
maxC = int(cmdlinearg('maxC', 1e9))

cx = []
chosen = set()
for _ in range(m):
  c = 0
  while True:
    c = random.randint(1, maxC)
    if c not in chosen:
      break
  chosen.add(c)

  cx += [[c, 0]]

cx.sort()

for i in range(m-n, m):
  cx[i][1] = 1

for i in reversed(range(m)):
  if cx[i][1] > 0:
    j = random.randint(0, i)
    cx[i][1] -= 1
    cx[j][1] += 1

random.shuffle(cx)
c = [i[0] for i in cx]
x = []
for i in range(m):
  x += [i+1]*cx[i][1]

random.shuffle(x)

print(n, m, k)
print(*x)
print(*c)
