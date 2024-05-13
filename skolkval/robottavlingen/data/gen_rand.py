#!/usr/bin/python3

import sys
import random
import math

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
nail_exists = int(cmdlinearg('nail_exists', 0))
n, m = random.randint(1, 15), random.randint(1, 15)

if nail_exists:
    m = min(n, m)
    print(n, m)
    a = [random.randint(1, 100) for _ in range(n)]
    b = []
    for i in range(m): b.append(a[i])
    print(" ".join(map(str, a)))
    random.shuffle(b)
    print(" ".join(map(str, b)))

else:
    print(n, m)
    print(" ".join(map(str, [random.randint(1, 100) for _ in range(n)])))
    print(" ".join(map(str, [random.randint(1, 100) for _ in range(m)])))

    