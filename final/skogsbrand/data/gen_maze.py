#!/usr/bin/python3

import sys
import random

default = {
    "n": 100,
    "m": 100,
    "T": 10**9,
    "maxx": 99999,
    "closed": 0,
    "extra_fire": 0,
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
# 'V' - optional fire

chamber = [" ## ",
           "#F E",
           " ## "]

maze = ["  V#########           ",   
        "  #   #     #          ",       
        " #  #  #  #  #         ",      
        "V##  #  #  #  #        ",      
        "#F #  #  #  #  #       ",
        " #  #  #  #  #  #      ",
        "  #  #  #  #  #  #     ",
        "   #  #  #  #  #  #    ",
        "   V#  #  #  #  #  #   ",
        "     #  #  #  #  #  #  ",
        "      #  #  #  #  # E# ",
        "       #  # #   #  #   ",
        "        #   ###   ##   ",
        "         ###   ###     "]


def main():
    def inbounds(x,y):
        return x >= 0 and x <= maxx and y >= 0 and y <= maxx
    def place(x,y,shape,close,option,nofire=0):
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
                    if ch == 'V' and option == 1 and nofire == 0:
                        tempf.append([x2,y2])
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
    extra_fire = int(cmdlinearg("extra_fire"))
    
    place(0,0,maze,closed,extra_fire)

    for i in range(0,100):
        xr = random.randint(23,maxx)
        yr = random.randint(23,maxx)
        place(xr,yr,chamber,1,0)
    
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

