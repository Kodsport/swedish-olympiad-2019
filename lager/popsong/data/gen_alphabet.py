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

def ch(i):
    if i == 26: return '_'
    return chr(ord('a') + i)

print(''.join(ch(i % 27) for i in range(n)))
