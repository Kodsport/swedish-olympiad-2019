#!/usr/bin/env python3

import sys
import random
import math

def cmdlinearg(name, default=None):
	for arg in sys.argv:
		if arg.startswith(name + "="):
			return arg.split("=")[1]
	assert default is not None, name
	return default

def solve(H,U):
	if U[1]*2 < H[1]:
		return 'E'
	elif U[1] != H[1]:
		return 'D'
	elif U[0]*2 < H[0]:
		return 'C'
	elif U[0] != H[0]:
		return 'B'
	else:
		return 'A'
 
random.seed(int(cmdlinearg('seed', sys.argv[-1])))

ans = str(cmdlinearg('ans'))

A = random.randint(1,30)
C = random.randint(1,30)
E = random.randint(1,30)
a = 0
c = 0
e = 0

print(str(A),str(C),str(E))

if ans == "A":
	a = A
	c = C
	e = E
if ans == "B":
	if A==1:
		A = 2
	a = random.randint(int(math.ceil(A/2.0)),A-1)
	c = C
	e = E
if ans == "C":
	a = random.randint(0,int(math.floor(A/2.0)))
	c = C
	e = E
if ans == "D":
	a = random.randint(0,A)
	if C==1:
		C = 2
	c = random.randint(int(math.ceil(C/2.0)),C-1)
	e = E
if ans == "E":
	a = random.randint(0,A)
	c = random.randint(0,int(math.floor(C/2.0)))
	e = E

assert(solve([A,C,E],[a,c,e])==ans)

print(a,c,e)