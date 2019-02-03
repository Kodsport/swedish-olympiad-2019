import string
import random
import sys

def multiIncreasingTestCase(size):
    mult = 1
    p = [0] * 20
    pN = 0
    for i in range(2, size):
        isPrime = 1
        for j in range(pN):
            if i % p[j] == 0:
                isPrime = 0
        if isPrime and mult * i < size:
            p[pN] = i
            pN += 1
            mult *= i
        if mult *i >= size:
            break
    tc = ['m' for _ in range(size)]
    for j in range(pN):
        pos = 0
        k = 0
        for pos in range(size // 2, size):
            if k >= p[j]: break
            if (pos - size // 2) % p[j] == k and (pos - size // 2) % (mult/p[j]) == 0:
                tc[pos] = random.choice(string.ascii_lowercase + '_')
                ++k;
                if tc[pos] == 'm': tc[pos] = '_'
    return ''.join(tc)

random.seed(int(sys.argv[-1]))

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert False

n = int(cmdlinearg('n'))

print(multiIncreasingTestCase(n))
