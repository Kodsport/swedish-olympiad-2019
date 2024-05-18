#!/usr/bin/env python3

import sys

# Usage: multationer_gen.py    startstring  targetlength  sequencelength
# Writes out unique solutions and marks sequences with identical multations with "SPECIAL"

N = 3  # alphabet length
M = 3  # max number of replacements
K = 3  # max replacement string length
ord0 = ord("A")  # first letter


def gen(n):  # generate all strings of length n
    return (
        [""]
        if n == 0
        else sum([[chr(ord0 + k) + x for k in range(N)] for x in gen(n - 1)], [])
    )


start = sys.argv[1]
length = int(sys.argv[2])
seqn = int(sys.argv[3])

poss = sum([gen(k + 1) for k in range(K)], [])
alph = gen(1)


def MLX(n, now, history):
    if n == 0:
        if len(now) == length and (now not in previous):
            if now in targets:
                targets[now] += 1
            else:
                targets[now] = 1
                mult[now] = ",   ".join([s + "->" + t for (s, t) in history])
                if len(set(history)) == 1:
                    mult[now] += "     SPECIAL"
        return
    for s in alph:
        if s in now:
            for t in poss:
                MLX(n - 1, now.replace(s, t), history + [(s, t)])


mult = {}
previous = {}
for mx in range(1, seqn + 1):
    targets = {}
    MLX(mx, start, [])
    previous.update(targets)

for target, cnt in targets.iteritems():
    if cnt == 1:
        print(target, "         ", mult[target])
