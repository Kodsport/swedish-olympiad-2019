import string
import random
import sys

def mixedSolutionTestCase(size):
    tc = [' ' for _ in range(size)]
    eq = [' ' for _ in range(size)]
    for i in range(100):
        s = random.randint(0, size - 1)
        modulo = random.randint(1, size // 2)
        lenEqual = random.randint(1, modulo)
        if lenEqual > size // (4 * modulo) and random.randint(0, 4) < 4:
            lenEqual = random.randint(1, size // (4 * modulo) + 1)
        numberTimes = random.randint(0, size // modulo)
        if numberTimes > size // (2 * modulo) and random.randint(0, 4) < 3:
            numberTimes = random.randint(0, size // (2*modulo))
        for j in range(lenEqual):
            eq[j] = random.choice(string.ascii_lowercase + '_')
        for j in range(numberTimes):
            for k in range(lenEqual):
                if s + j * modulo + k >= size:
                    break
                tc[s+j*modulo+k] = eq[k]
    for i in range(size):
        if tc[i] == ' ':
            tc[i] = random.choice(string.ascii_lowercase + '_')
    return ''.join(tc)

random.seed(int(sys.argv[-1]))

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert False

n = int(cmdlinearg('n'))

print(mixedSolutionTestCase(n))
