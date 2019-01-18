import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
ns = list(map(int, cmdlinearg('n').split(',')))
ms = list(map(int, cmdlinearg('m').split(',')))
edge = int(cmdlinearg('edge', 0))
N = random.randint(ns[0], ns[-1])
M = random.randint(ms[0], ms[-1])
assert N > 1
assert M > 1
assert N > 2 or M > 2
xmode = cmdlinearg('xmode','diff')
ymode = cmdlinearg('ymode','diff')

def impossible(x1, x2, y1, y2):
    if x1 == x2:
        return abs(y1 - y2) < 3 and min(y1, y2) == 0 and max(y1, y2) == M-1
    if y1 == y2:
        return abs(x1 - x2) < 3 and min(x1, x2) == 0 and max(x1, x2) == N-1
    return False

def get_coords(maxCoord, mode):
    if mode == "next": #the generated values have a distance of 1 between them
        assert maxCoord >= 2
        c = random.randrange(maxCoord - 1)
        if edge and random.choice([True, False]):
            c = random.choice([0, maxCoord - 2])
        return c, c + 1
    if mode == "close": #the generated values have a distance of 2 between them
        assert maxCoord >= 3
        c = random.randrange(maxCoord - 2)
        if edge and random.choice([True, False]):
            c = random.choice([0, maxCoord - 3])
        return c, c + 2
    if mode == "same": #the generated values are the same
        c = random.randrange(maxCoord)
        if edge and random.choice([True, False]):
            c = random.choice([0, maxCoord - 1])
        return c, c
    if mode == "diff": #the generated values are different
        assert maxCoord >= 2
        c1, c2 = random.sample(range(maxCoord), 2)
        if edge and 0 not in [c1, c2] and maxCoord-1 not in [c1, c2] and random.choice([True, False]):
            c1 = random.choice([0, maxCoord - 1])
        return c1, c2
    assert False, "Invalid mode"

while True:
    x1, x2 = get_coords(N, xmode)
    y1, y2 = get_coords(M, ymode)
    if random.choice([True, False]):
        x1, x2 = x2, x1
    if random.choice([True, False]):
        y1, y2 = y2, y1
    if not impossible(x1, x2, y1, y2):
        break

print(N, M)
print(x1, y1, x2, y2)
