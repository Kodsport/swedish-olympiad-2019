#!/usr/bin/env python3

from common import *

print(n, m, k)
for i in range(n):
    line = [random.randint(0, 100) for _ in range(m)]
    print(*line)
