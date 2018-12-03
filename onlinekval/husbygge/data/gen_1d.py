#!/usr/bin/env python3

from common import *

print(n, m, k)
for i in range(n):
    line = [i * 101 // m for _ in range(m)]
    print(*line)
