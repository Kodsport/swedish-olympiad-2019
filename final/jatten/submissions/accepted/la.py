def dist(x1,y1,x2,y2):
    return (x1-x2)**2+(y1-y2)**2
def test(x,y):
    d1 = dist(x,y,x1,y1)
    d2 = dist(x,y,x2,y2)
    d3 = dist(x2,y2,x1,y1)
    dd1 = d1**0.5
    dd2 = d2**0.5
    dd3 = d3**0.5
    if abs(2*max(dd1,dd2,dd3)-(dd1+dd2+dd3)) < 10**(-5): return False
    if 0 <= x < N and 0 <= y < M and 2*max(d1,d2,d3) > d1+d2+d3:
        return True
    return False
N,M = map(int,raw_input().split())
x1,y1,x2,y2 = map(int,raw_input().split())
for x in range(x1-1,x1+2):
    for y in range(y1-1,y1+2):
        if x == x1 and y == y1: continue
        if test(x,y):
            print x,y
            exit()
for x in range(x2-1,x2+2):
    for y in range(y2-1,y2+2):
        if x == x2 and y == y2: continue
        if test(x,y):
            print x,y
            exit()
