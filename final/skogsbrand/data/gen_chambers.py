#!/usr/bin/python3

import sys
import random

default = {
    "n": 100,
    "m": 100,
    "T": 10**9,
    "maxx": 99999,
    "closed": 0,
    "small_only": 0,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

inf = 3*10**9
fire = []
walls = []
S = set()

# ' ' - nothing
# '#' - wall
# 'F' - fire
# 'E' - entrance (wall or nothing)

chamber = [" ## ",
           "#F E",
           " ## "]

L_chamber = ["  E ",
             " # #",
             " # #",
             "#F #",
             " ## "]

maze = ["  ### ",
        " #   #",
        "#F # #",
        " ##  #",
        "E   # ",
        " ###  "]

shapes = [chamber,L_chamber,maze]

def main():
    def inbounds(x,y):
        return x >= 0 and x <= maxx and y >= 0 and y <= maxx
    def place(x,y,shape,close,nofire):
        tempf = []
        tempw = []
        dx = 0
        for row in shape:
            dy = 0
            for ch in row:
                x2 = x+dx
                y2 = y+dy
                if (inf*x2+y2 not in S) and inbounds(x2,y2):
                    if ch == '#':
                        tempw.append([x2,y2])
                    if ch == 'F' and nofire == 0:
                        tempf.append([x2,y2])
                    if ch == 'E' and close == 1:
                        tempw.append([x2,y2])
                dy += 1
            dx += 1
        if len(tempf)+len(fire) <= n and len(tempw)+len(walls) <= m:
            for pt in tempf:
                fire.append(pt)
                S.add(inf*pt[0]+pt[1])
            for pt in tempw:
                walls.append(pt)
                S.add(inf*pt[0]+pt[1])
                
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    m = int(cmdlinearg("m"))
    T = int(cmdlinearg("T"))
    maxx = int(cmdlinearg("maxx"))
    closed = int(cmdlinearg("closed"))
    small_only = int(cmdlinearg("small_only"))
    
    for i in range(0,1000):
        xr = random.randint(0,maxx)
        yr = random.randint(0,maxx)
        shape = shapes[random.randint(0,len(shapes)-1)]
        if small_only:
            shape = shapes[0]
        close = random.randint(0,1)
        if closed:
            close = 1
        nofire = random.randint(0,4)
        if nofire > 0:
            nofire = 1
        nofire = 1-nofire
        place(xr,yr,shape,close,nofire)

    if len(fire) == 0:
        for i in range(0,maxx+1):
            for j in range(0,maxx+1):
                if i*inf+j not in S:
                    fire.append([i,j])
                    break
            if len(fire) != 0:
                break
    
    print(len(fire),len(walls),T)
    for p in fire:
        print(p[0],p[1])
    for p in walls:
        print(p[0],p[1])
    
    
if __name__ == "__main__":
    main()

