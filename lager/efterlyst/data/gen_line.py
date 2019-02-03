#!/usr/bin/python3

import sys
import random

default = {
    "n": 10,
    "k": 4,
    "maxw": 1000000000,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    k = int(cmdlinearg("k"))
    maxw = int(cmdlinearg("maxw"))

    specials = random.sample(range(1,n+1),k)
    print(n,n-1,len(specials))
    for i in range(0,len(specials)):
        ends = " "
        if i == len(specials)-1:
            ends = "\n"
        print(specials[i],end=ends)
    for i in range(0,n-1):
        w = random.randint(1,maxw)
        print(i+1,i+2,w)



if __name__ == "__main__":
    main()

