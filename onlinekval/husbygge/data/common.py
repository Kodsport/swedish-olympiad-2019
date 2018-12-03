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

print(cmdlinearg('tc'))

n = int(cmdlinearg('n'))
m = int(cmdlinearg('m'))
k = int(cmdlinearg('k'))
