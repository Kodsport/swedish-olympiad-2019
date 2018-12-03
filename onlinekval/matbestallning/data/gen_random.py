#!/usr/bin/env pypy
#First placing one of each type, then randomizing the rest.

from __future__ import print_function
import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

def max_possible(x, c):
  v = [[y, 0] for y in c]
  for i in x:
    v[i-1][1] += 1
  v.sort(reverse=True)
  free, ans = 0, 0
  for p in v:
    if p[1] == 0:
      free += 1
    else:
      ans += 1
      while free > 0 and p[1] > 1:
        p[1] -= 1
        free -= 1
        ans += 1

  return ans

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n'))
m = int(cmdlinearg('m'))
k = int(cmdlinearg('k', -1))
maxC = int(cmdlinearg('maxC', 1e9))
possible = cmdlinearg('possible', 'either')
allXSame = cmdlinearg('allXSame', 'false')
easyPrices = cmdlinearg('easyPrices', 'false')
distinctPrices = int(cmdlinearg('distinctPrices', -1))

x = [random.randint(1, m) for _ in range(n)]
c = [random.randint(1, maxC) for _ in range(m)]
if distinctPrices != -1:
  prices = [random.randint(1, maxC) for _ in range(distinctPrices)]
  c = [random.choice(prices) for _ in range(m)]

if easyPrices == 'true':
  c = [i+1 for i in range(m)]

if allXSame == 'true':
  x = [random.randint(1, m)]*n

if k == -1:
  k = random.randint(len(set(x)), n)

if possible == 'true':
  # Decrease k until possible
  k = n
  req = max_possible(x, c)
  while req < k:
    assert k != 1
    k = random.randint(max(1, int(k*0.95)-1), max(k-1, 1))

if possible == 'false':
  k = (n+1)//2
  while k <= max_possible(x, c):
    assert k != n
    if allXSame != 'true':
      # Make one person want the most expensive thing
      top = c.index(max(c)) + 1
      for i in range(n):
        if x[i] != top:
          x[i] = top
          break

    # and make the required number of unique values higher
    k = random.randint(min(k+1, n), min(n, int(k*2)+1))
    if k == n:
      break

print(n, m, k)
print(*x)
print(*c)
