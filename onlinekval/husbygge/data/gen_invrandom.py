#!/usr/bin/env python3

from common import *

print(n, m, k)
for i in range(n):
    line = [round(100 / random.uniform(1, 200)) for _ in range(m)]
    print(*line)
