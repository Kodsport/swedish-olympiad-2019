#!/usr/bin/python3

import sys
import random

default = {
    "n": 10,
    "xmax": 10**9,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    xmax = int(cmdlinearg("xmax"))
    print(n)
    S = set()
    for i in range(0,n):
        a = random.randint(0,xmax)
        b = random.randint(0,xmax)
        while a*(10**9)+b in S:
            a = random.randint(0,xmax)
            b = random.randint(0,xmax)
        S.add(a*(10**9)+b)
        print(a,b)

if __name__ == "__main__":
    main()

