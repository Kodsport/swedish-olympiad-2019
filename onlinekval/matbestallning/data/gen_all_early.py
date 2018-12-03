#!/usr/bin/env python3

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
k = int(cmdlinearg('k', random.randint(1, n)))
cover = int(cmdlinearg('cover', 0))
choices = int(cmdlinearg('choices'))
maxC = int(cmdlinearg('maxC', 1e9))
easyPrices = cmdlinearg('easyPrices', 'false')

c = [random.randint(1, maxC) for _ in range(m)]
if easyPrices == 'true':
  c = [i+1 for i in range(m)]

chooseList = [(p, i+1) for i, p in enumerate(c)]
chooseList.sort()
chooseFrom = [i for _, i in chooseList[:choices]]

x = [random.choice(chooseFrom) for _ in range(n-cover)]
x = x + [chooseList[i][1] for i in range(0, cover)]
random.shuffle(x)

print(n, m, k)
print(*x)
print(*c)
