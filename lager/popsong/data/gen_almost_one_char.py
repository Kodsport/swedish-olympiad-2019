#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))


def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert False

def ch():
    p = random.randint(0, 26)
    if p == 26: return '_'
    return chr(ord('a') + p)
p = ch()

def ch2():
    t = random.randint(0, 5)
    if t == 0:
        return ch()
    return p

n = int(cmdlinearg('n'))
print(''.join(ch2() for _ in range(n)))
