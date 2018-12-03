A,C,E = map(int, input().split())
a,c,e = map(int, input().split())

if c*2 < C:
   print('E')
elif c != C:
   print('D')
elif a*2 < A:
   print('C')
elif a != A:
   print('B')
else:
   print('A')
