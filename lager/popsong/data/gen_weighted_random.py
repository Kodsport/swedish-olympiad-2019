import string
import random
import sys

def weightRandomTestCase(size):
    weightSum = 164
    weight = [weightSum] * 27
    weight[0] = 100
    weight[1] = 140
    weight[2] = 150
    weight[3] = 157
    weight[4] = 161
    weight[5] = 163
    tc = [' ' for _ in range(size)]
    for i in range(size):
        j = random.randint(0, weightSum - 1)
        for k in range(7):
            if weight[k] > j:
                tc[i] = chr(ord('a') + k)
                break
    return ''.join(tc)

random.seed(int(sys.argv[-1]))

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert False

n = int(cmdlinearg('n'))

print(weightRandomTestCase(n))
