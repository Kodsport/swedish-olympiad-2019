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

def chs(le):
    return ''.join(ch() for _ in range(le))

before = int(cmdlinearg('before'))
after = int(cmdlinearg('after'))
n = int(cmdlinearg('n'))

m = (n - before - after) // 2 - 1

res = chs(before) + ('a' * m + 'b') * 2 + chs(after)

print(''.join(res))
