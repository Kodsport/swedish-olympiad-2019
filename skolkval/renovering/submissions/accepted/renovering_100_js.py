#!/usr/bin/env python3
input()
N = sorted(map(int, input().split()), reverse=True)
H = sorted(map(int, input().split()), reverse=True)

res = []
for need in N:
    if H and H[0] >= need:
        H = H[1:]
        continue
    else:
        res.append(need)
print(len(res))
print(*reversed(res))
