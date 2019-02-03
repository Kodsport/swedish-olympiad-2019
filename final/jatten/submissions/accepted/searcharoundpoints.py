

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
for dx in range(-10,11):
    for dy in range(-10,11):
        x3,y3=x1+dx,y1+dy
        if valid(((x1,y1),(x2,y2),(x3,y3)),n,m):
            print x3,y3
            exit(0)
        x3,y3=x2+dx,y2+dy
        if valid(((x1,y1),(x2,y2),(x3,y3)),n,m):
            print x3,y3
            exit(0)
print "no point found"
