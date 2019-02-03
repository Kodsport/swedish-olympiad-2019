#!/usr/bin/python3

import sys
import random

default = {
    "n": 100,
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
    maxw = int(cmdlinearg("maxw"))

    edges = []
    
    spec = 1
    t = 2
    now = 1
    while t <= maxw:
        edges.append([now,now+1,t])
        now += 1
        spec += 1
        t *= 2
    t = 2
    old = 1
    nex = now+1
    while t <= maxw:
        edges.append([old,nex,t])
        old = nex
        nex += 1
        spec += 1
        t *= 2

    edges.append([spec,spec+1,1])
    edges.append([spec+1,spec+2,1])
    edges.append([spec+2,spec+3,1])
    edges.append([spec+3,spec,2])

    for i in range(0,n-spec-3):
        edges.append([spec+i+4,1,1])

    print(n,len(edges),spec+1)
    
    for i in range(0,spec+1):
        ends = " "
        if i == spec:
            ends = "\n"
        print(i+1,end=ends)
        
    for i in edges:
        print(i[0],i[1],i[2])

if __name__ == "__main__":
    main()

