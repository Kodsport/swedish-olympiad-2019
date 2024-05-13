import sys

N=3   # alphabet length
M=3   # max number of replacements
K=3   # max replacement string length
ord0=ord("A")   #first letter

def gen(n):  #generate all strings of length n
	return [""] if n==0 else sum([[chr(ord0+k)+x for k in range(N)] for x in gen(n-1)],[])

[start,goal]=sys.stdin.read().split()

poss=sum([gen(k+1) for k in range(K)],[])
alph=gen(1)

def MLX(n,now,history):
	if(n==0):
		if now==goal:
			for (s,t) in history:
				print(s, t)
			exit(0)
		return 
	for s in alph:
		if s in now:  #Don't try it if not present
			for t in poss:
				MLX(n-1,now.replace(s,t),history+[(s,t)])

for mx in range(1,M+1): MLX(mx,start,[])
