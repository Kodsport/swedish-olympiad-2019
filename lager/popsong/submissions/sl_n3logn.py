#!/usr/bin/env python2
S = raw_input()

def go(p, le, l):
    strs = le // l
    for k in range(l):
        w = S[p + (l - 1 - k)]
        for t in range(strs):
            idx = p + t * l + (l - 1 - k)
            if S[idx] != w:
                return strs * k
    return strs * l

ans = 0
for p in range(len(S)):
    for s in range(p+2, len(S)+1):
        le = s - p
        for l in range(1, le//2 + 1):
            if le % l != 0:
                continue
            ans = max(ans, go(p, le, l))

print(ans)
