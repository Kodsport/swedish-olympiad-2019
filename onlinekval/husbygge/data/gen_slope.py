#!/usr/bin/env python3

from common import *

print(n, m, k)
for i in range(n):
    line = [max(0, min(100, i * 101 // m + random.randint(-5, 5))) for _ in range(m)]
    print(*line)
