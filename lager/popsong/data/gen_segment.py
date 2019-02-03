import string
import random
import sys

def segmentTestCase(size):
    tc = [' ' for _ in range(size)]
    eq = [' ' for _ in range(size)]
    for i in range(20):
        ln = random.randint(1, 17)
        num = random.randint(1, (size // ln + 30) // 3)
        for j in range(ln):
            eq[j] = random.choice(string.ascii_lowercase + '_')
        for j in range(num):
            pos = random.randint(0, size - 1)
            for k in range(max(0, min(ln, size - pos))):
                tc[k + pos] = eq[k]
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

print(segmentTestCase(n))
