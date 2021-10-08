#!/usr/bin/python3

import sys
import random

default = {
    "n": 100,
    "dx": 1,
    "dy": 0,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]




def main():              
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    dx = int(cmdlinearg("dx"))
    dy = int(cmdlinearg("dy"))

    x = 0
    y = 0
    print(n)
    for i in range(0,n):
        print(x,y)
        x += dx
        y += dy
    
    
if __name__ == "__main__":
    main()

