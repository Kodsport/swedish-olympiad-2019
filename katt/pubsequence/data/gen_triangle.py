#!/usr/bin/python3

import sys
import random

default = {
    "x1": 20,
    "y1": 20,
    "x2": 21,
    "y2": 21,
    "x3": 22,
    "y3": 22,

}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

def main():
    random.seed(int(sys.argv[-1]))
    x1 = int(cmdlinearg("x1"))
    y1 = int(cmdlinearg("y1"))
    x2 = int(cmdlinearg("x2"))
    y2 = int(cmdlinearg("y2"))
    x3 = int(cmdlinearg("x3"))
    y3 = int(cmdlinearg("y3"))
    print(3)
    print(x1,y1)
    print(x2,y2)
    print(x3,y3)

if __name__ == "__main__":
    main()

