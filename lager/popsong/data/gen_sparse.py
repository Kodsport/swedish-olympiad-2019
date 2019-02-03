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
k = int(cmdlinearg('k'))
mat = ['p'] * n
for i in random.sample(range(n), k):
    mat[i] = 'x'

print(''.join(mat))
