from collections import deque

def solve(grid, k):
    r = len(grid)
    c = len(grid[0])
    if r+c <= k:
        return r-1+c-1

    q = deque([])
    q.append((0,0,0,0))
    seen = [[[False] * (k+1) for j in range(c)] for l in range(r)]
    while len(q)>0:
        x=0
        y=0
        f=0
        s=0
        (x,y,f,s) = q.popleft()
        if x<0 or x>=r or y<0 or y>=c:
            continue
        assert grid[x][y] in "#."
        f += (grid[x][y] == '#')
        if f>k or seen[x][y][f]:
            continue
        seen[x][y][f] = True
        if x==r-1 and y==c-1:
           return s
        q.append((x,y-1,f,s+1))
        q.append((x+1,y,f,s+1))
        q.append((x,y+1,f,s+1))
        q.append((x-1,y,f,s+1))
    return -1

