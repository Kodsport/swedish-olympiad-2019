#!/usr/bin/env python3

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))

numRows = int(cmdlinearg('n'))
numCols = int(cmdlinearg('m'))
numClasses = int(cmdlinearg('k'))

ans = random.randint(1, min(numClasses, numCols))

componentClasses = [[] for j in range(ans)]

classesPerm = [i for i in range(numClasses)]
random.shuffle(classesPerm)

for i in range(numClasses):
    comp = i if i < ans else random.randrange(ans)
    componentClasses[comp].append(classesPerm[i])

colComponents = [ 0 ] * numCols
for i in range(numCols):
    colComponents[i] = i if i < ans else random.randrange(ans)
random.shuffle(colComponents)

grid = [[ 0 ] * numCols for j in range(numRows)]
for c in range(numCols):
    classes = componentClasses[colComponents[c]]
    for r in range(numRows):
        grid[r][c] = classes[random.randrange(len(classes))]

print(numRows, numCols, numClasses)
for row in grid:
    print("".join(chr(ord('A') + x) for x in row))
