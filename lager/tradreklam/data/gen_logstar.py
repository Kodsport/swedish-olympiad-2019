#!/usr/bin/python3

import sys
import random

default = {
    "n": 40,
    "b": 30000,
    "maxpop": 30000,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

# A star graph of depth 2, where the root has n/log(n) children
# Each child has log(n) children with weight and population 2^i

vertices = 1
edges = []
pop = []

def add_edge(i,w,p):
    global vertices
    edges.append([i,vertices,w])
    pop.append(p)
    vertices += 1

def main():   
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    maxw = int(cmdlinearg("b"))
    maxpop = int(cmdlinearg("maxpop"))


    
    while vertices < n:
        add_edge(0,maxw,1)
        i = vertices-1
        t = 1
        while (vertices < n) and (t <= maxw) and (t <= maxpop):
            add_edge(i,t,t)
            t *= 2

    assert(n == len(edges)+1)
    print(n,maxw)
    for i in range(0,n-1):
        ends = " "
        if i == n-2:
            ends = "\n"
        print(pop[i],end=ends)
        
    for i in range(0,n-1):
        print(edges[i][0]+1, edges[i][1]+1, edges[i][2])

if __name__ == "__main__":
    main()
