#!/usr/bin/python3

import sys
import random

default = {
    "n": 100,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    a = n//2+n%2
    b = n//2
    m = a+2*b-2
    k = b
    print(n,m,k)
    for i in range(0,k):
        ends = " "
        if i == k-1:
            ends = "\n"
        print(i+1, end = ends)
    for i in range(0,k-1):
        print(i+1,i+2,3)
    for i in range(0,k):
        print(i+1,k+1,2)
    for i in range(0,a-1):
        print(k+1,k+i+2,1)

if __name__ == "__main__":
    main()
