import random

def valid(pts,n,m):
    def sqlen(p1,p2):
        return (p1[0]-p2[0])**2 + (p1[1]-p2[1])**2

    for p in pts:
        if p[0]<0 or p[0] >=n or p[1]<0 or p[1] >=m:
            return False
    sqsides = []
    for i in range(-1,2):
        p1=pts[i]
        p2=pts[i+1]
        sqsides.append(sqlen(p1,p2))
    sqsides.sort()
    if sqsides[0] + sqsides[1] >= sqsides[2]:
        return False #icke trubbig
    if (sqsides[2]-sqsides[1]-sqsides[0])**2 == 4*sqsides[0]*sqsides[1]:
        return False #platt
    return True

n,m=map(int,raw_input().split())
x1,y1,x2,y2=map(int,raw_input().split())
while True:
    x=random.randint(0,n-1)
    y=random.randint(0,m-1)
    pts=((x1,y1),(x2,y2),(x,y))
    if valid(pts,n,m):
        print " ".join(map(str,pts[2]))
        break
