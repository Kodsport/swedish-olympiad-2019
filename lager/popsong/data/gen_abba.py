#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))


def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert False

n = int(cmdlinearg('n'))

res = []
for i in range(n):
    res.append('r' if bin(i).count('1') % 2 else 's')

print(''.join(res))
