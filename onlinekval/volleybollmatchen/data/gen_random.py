#!/usr/bin/env python3
#Team A winning a point with probability probA

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
probA = float(cmdlinearg('probA'))
easyWin = int(cmdlinearg('easyWin'))

points = ""
aScore = 0
bScore = 0

def pointA():
	global aScore,bScore,points
	aScore+=1
	points+="A"

def pointB():
	global aScore,bScore,points
	bScore+=1
	points+="B"

def playSet(winScore):
	global aScore,bScore
	aScore = 0
	bScore = 0
	while True:
		if random.uniform(0,1)<probA:
			pointA()
		else:
			pointB()

		if easyWin==1:
			if aScore==winScore-1 and bScore==winScore-2:
				pointA()
			elif bScore==winScore-1 and aScore==winScore-2:
				pointB()
		else:
			if aScore==winScore-2:
				while bScore<aScore:
					pointB()
			if bScore==winScore-2:
				while aScore<bScore:
					pointA()

		if aScore>=winScore and aScore>=2+bScore:
			return "A"
		
		if bScore>=winScore and bScore>=2+aScore:
			return "B"

winSet1 = playSet(25)
winSet2 = playSet(25)

if winSet1 != winSet2:
	playSet(15)

print(len(points))
print(points)