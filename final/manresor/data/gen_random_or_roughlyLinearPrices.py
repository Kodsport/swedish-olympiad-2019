import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

def get_roughly_linear(lst):
    out = set([max(2,min(10**4,2*((lsti+random.randint(-3,3))//2))) for lsti in lst])
    while len(out) < len(lst): out.add(2*random.randint(1,5*10**3))
    return list(out)

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
N = int(cmdlinearg('N',10**5))
M = int(cmdlinearg('M',10))
K = int(cmdlinearg('K',N))
days = int(cmdlinearg('days'))
piMax = int(cmdlinearg('piMax'))
mode = cmdlinearg('mode', 'random') #can be 'random' or 'rlinear'
factor = int(cmdlinearg('factor', 10**3))
spread = int(cmdlinearg('spread', 4*10**2))

giMax = days
if int(cmdlinearg('compactGi', 0)):
    giMax = M

assert days >= N, 'days too small'
assert giMax >= M, 'giMax too small'
assert piMax >= M, 'piMax too small'

ds = list(range(1, days+1))
gs = list(range(1, giMax+1))
ps = list(set([2*random.randint(1,piMax//2) for _ in range(10*N)]))
rs = list(range(1, days+1))

purchases = sorted(random.sample(ds, N))
durs = sorted(random.sample(gs, M))
if mode == 'random':
    prices = sorted(random.sample(ps, M))
else:
    prices = sorted(get_roughly_linear(durs))
sales = sorted(random.sample(rs, K))

print(N,M,K)
print(*purchases)
print(*durs)
print(*prices)
print(*sales)
