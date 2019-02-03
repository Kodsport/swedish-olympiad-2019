#!/usr/bin/python3

import sys
import random

default = {
    "n": 10,
    "m": 10,
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
    m = int(cmdlinearg("m"))
    k = int(cmdlinearg("k"))
    maxw = int(cmdlinearg("maxw"))

    specials = random.sample(range(2,n+1),k)
    print(n,m,len(specials))
    for i in range(0,len(specials)):
        ends = " "
        if i == len(specials)-1:
            ends = "\n"
        print(specials[i],end=ends)
    for i in range(0,n-1):
        w = random.randint(1,maxw)
        print(1,i+2,w)
    S = set()
    for i in range(0,m-n+1):
        a = random.randint(2,n)
        b = random.randint(2,n)
        while (a == b) or (a*n+b in S):
            a = random.randint(2,n)
            b = random.randint(2,n)
        w = random.randint(1,maxw)
        S.add(a*n+b)
        S.add(b*n+a)
        print(a,b,w)



if __name__ == "__main__":
    main()

