#!/usr/bin/env python3

from common import *

val = random.randint(1, 100)

print(n, m, k)
for i in range(n):
    line = [val for _ in range(m)]
    print(*line)
