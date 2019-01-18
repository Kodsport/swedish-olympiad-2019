#!/usr/bin/python3

import sys
import random

default = {
    "n": 10,
    "m": 10,
    "T": 1,
    "maxx": 5,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    m = int(cmdlinearg("m"))
    T = int(cmdlinearg("T"))
    maxx = int(cmdlinearg("maxx"))
    print(n,m,T)
    S = set()
    for i in range(0,n+m):
        x = random.randint(0,maxx)
        y = random.randint(0,maxx)
        while x*(10**10)+y in S:
            x = random.randint(0,maxx)
            y = random.randint(0,maxx)
        S.add(x*(10**10)+y)
        print(x,y)
            
    
if __name__ == "__main__":
    main()

