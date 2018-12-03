#!/usr/bin/env python3
H = list(map(int, input().split()))
U = list(map(int, input().split()))
if U[1]*2 < H[1]:
    print('E')
elif U[1] != H[1]:
    print('D')
elif U[0]*2 < H[0]:
    print('C')
elif U[0] != H[0]:
    print('B')
else:
    print('A')
