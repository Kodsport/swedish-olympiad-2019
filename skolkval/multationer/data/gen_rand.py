#!/usr/bin/python3

import sys
import random
import math

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))

n_is = int(cmdlinearg('n_is'))
maxk = int(cmdlinearg('maxk'))
same_mult = int(cmdlinearg('same_mult', 0))

s = "".join(random.choice("ABC") for _ in range(n_is))
print(s)
prev_mult = ("","")
for i in range(random.randint(2, 3)):
    if i>0 and same_mult:
        toReplace, pattern = prev_mult
    else:
        toReplace = random.choice("ABC")
        while not s.count(toReplace): 
            toReplace = random.choice("ABC")
        # print((10-len(s))//s.count(toReplace)+1)
        pattern = "".join(random.choice("ABC") for _ in range(random.randint(max(1, min(maxk, (10-len(s))//s.count(toReplace)+1)), min(maxk, (10-len(s))//s.count(toReplace)+1))))

    next = ""
    for c in s:
        next+=(c if c!=toReplace else pattern)
    s = next
    #print(toReplace, pattern)
    
print(s)
