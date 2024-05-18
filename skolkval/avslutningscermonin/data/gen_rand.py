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
n = int(cmdlinearg("n"))
k = int(cmdlinearg("k"))
alpha = int(cmdlinearg("alpha"))
letters = [chr(ord("A") + i) for i in range(alpha)]

s = letters
for i in range(n - alpha):
    s.append(random.choice(letters))
random.shuffle(s)
print("".join(s))
print(k)
