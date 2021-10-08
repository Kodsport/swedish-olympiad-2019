#!/usr/bin/python3

import sys
import random

default = {
    "n": 100,
    "isolated": 10,
    "maxx": 1000000000,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]




def main():              
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    isolated = int(cmdlinearg("isolated"))
    maxx = int(cmdlinearg("maxx"))
    print(n)
    startx = random.randint(0,maxx-n)
    starty = random.randint(0,maxx-n)
    m = n-isolated
    S = set()
    L = int(2*(m**0.5))
    for i in range(0,m):
        x = startx + random.randint(0,L)
        y = starty + random.randint(0,L)
        while x*maxx+y in S:
            x = startx + random.randint(0,L)
            y = starty + random.randint(0,L)
        S.add(x*maxx+y)
        print(x,y)
    for i in range(0,isolated):
        x = random.randint(0,maxx)
        y = random.randint(0,maxx)
        while x*maxx+y in S:
            x = random.randint(0,maxx)
            y = random.randint(0,maxx)
        S.add(x*maxx+y)
        print(x,y)
    
    
    
if __name__ == "__main__":
    main()

