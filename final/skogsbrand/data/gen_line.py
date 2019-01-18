#!/usr/bin/python3

import sys
import random

default = {
    "n": 100,
    "m": 100,
    "T": 10**9,
    "maxx": 99999,
    "dx": 1,
    "dy": 0,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]




def main():
    def inbounds(x,y):
        return x >= 0 and x <= maxx and y >= 0 and y <= maxx

                
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    m = int(cmdlinearg("m"))
    T = int(cmdlinearg("T"))
    maxx = int(cmdlinearg("maxx"))
    dx = int(cmdlinearg("dx"))
    dy = int(cmdlinearg("dy"))
    
    points = []
    startx = 0
    starty = 0

    while inbounds(startx,starty):
        points.append([startx,starty])
        startx += dx
        starty += dy

    out = random.sample(points,min(n+m,len(points)))
    random.shuffle(out)

    if n+m > len(points):
        n = len(points)
        m = 0
    
    print(n,m,T)
    for pt in out:
        print(pt[0],pt[1])
    
    
if __name__ == "__main__":
    main()

