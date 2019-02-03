import string
import random
import sys

def increasingTestCase(size, modulo, d):
    tc = [' ' for _ in range(size)]
    inRow = [0 for _ in range(size)]
    for i in range(modulo):
        if d:
            inRow[i] = i + 1
        else:
            inRow[i] = modulo - i
        tc[i] = random.choice(string.ascii_lowercase + '_')

    for i in range(modulo, size):
        if inRow[i - modulo] == 1:
            inRow[i] - modulo
            tc[i] = random.choice(string.ascii_lowercase + '_')
        else:
            inRow[i] = inRow[i - modulo] - 1
            tc[i] = tc[i - modulo]

    return ''.join(tc)

random.seed(int(sys.argv[-1]))

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert False

n = int(cmdlinearg('n'))
mod = int(cmdlinearg('mod'))
d = int(cmdlinearg('d'))

print(increasingTestCase(n, mod, d))
