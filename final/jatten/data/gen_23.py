import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

index = int(cmdlinearg('index'))

n = 3
m = 2
x1 = y1 = 0
x2 = y2 = 1

if index & 1:
    x1 ^= 1
    x2 ^= 1

if index & 2:
    x1 += 1
    x2 += 1

if index & 4:
    n,m = m,n
    x1,y1 = y1,x1
    x2,y2 = y2,x2

if random.choice([True, False]):
    x1,y1,x2,y2 = x2,y2,x1,y1

print(n, m)
print(x1, y1, x2, y2)
