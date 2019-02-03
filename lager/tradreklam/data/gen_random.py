#!/usr/bin/python3

import sys
import random
import math

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n'))
mode = cmdlinearg('mode')
shuf = cmdlinearg('shuffle', 'yes')
c1 = int(cmdlinearg('c1', 0))
exact = int(cmdlinearg('exact', 0))
budget = int(cmdlinearg('b'))
max_cost = int(cmdlinearg('cost', -1))
if max_cost == -1:
    br = float(cmdlinearg('br', 0.5))
    max_cost = int(budget / br)
max_pop = int(cmdlinearg('maxpop', 30000))

def gen_tree(n, mode):
    eds = []
    assert mode in ['random', 'star', 'line', 'shallow', 'deep', 'deeper', 'degtwo']
    depth = [0]
    deg = [0] * n
    for i in range(1, n):
        if mode == 'random':
            pred = random.randrange(i)
        elif mode == 'star':
            pred = 0
        elif mode == 'line':
            pred = i-1
        elif mode == 'shallow':
            pred = int(random.uniform(0, i**0.2) ** 5)
        elif mode == 'deep':
            pred = i-1 - int(random.uniform(0, i**0.1) ** 10)
        elif mode == 'deeper':
            if i < 4:
                pred = random.randrange(i)
            else:
                hi = math.log2(math.log2(i))
                pred = i - int(2 ** 2 ** min(random.uniform(-3, hi), random.uniform(-3, hi), random.uniform(-3, hi)))
        elif mode == 'degtwo':
            while True:
                pred = random.randrange(i)
                if deg[pred] < 2:
                    break
        else:
            assert False
        assert 0 <= pred < i
        deg[pred] += 1
        eds.append((pred, i))
        depth.append(depth[pred] + 1)
    print('depth =', max(depth), file=sys.stderr)
    return eds

def assign_weights(eds, pop):
    if c1:
        ret = []
        for (a, b) in eds:
            ret.append((a, b, 1))
        return ret

    adjList = [[] for _ in range(n)]
    for (a, b) in eds:
        adjList[a].append(b)
        adjList[b].append(a)

    st = [(0, -1)]
    pars = [None] * n
    visits = []
    while st:
        ind, par = st.pop()
        assert pars[ind] is None
        pars[ind] = par
        visits.append(ind)
        for y in adjList[ind]:
            if y != par:
                st.append((y, ind))
    assert None not in pars

    sum_pop = sum(pop)
    pop2 = pop[:]
    for i in reversed(visits):
        pop2[pars[i]] += pop2[i]

    ret = []
    for i in range(1, n):
        rel_pop = pop2[i] / sum_pop
        if exact == 1:
            cost = math.ceil(max_cost * rel_pop)
        elif exact == 2:
            cost = pop2[i]
        else:
            cost = math.ceil(max_cost * rel_pop + random.uniform(0, (rel_pop * max_cost) ** 0.5))
        cost = min(cost, budget + 1)
        cost = max(cost, 1)
        ret.append((i, pars[i], cost))
    return ret

pop = [random.randint(0, max_pop) for _ in range(n)]

tr = gen_tree(n, mode)

ren = list(range(n))
if shuf == 'all':
    random.shuffle(ren)
elif shuf == 'yes':
    del ren[0]
    random.shuffle(ren)
    ren = [0] + ren
else:
    assert shuf == 'no'

tr2 = []
for (a, b) in tr:
    tr2.append((ren[a], ren[b]))
tr = tr2

eds = assign_weights(tr, pop)

if shuf != 'no':
    eds2 = []
    for (a, b, w) in eds:
        if random.choice([True, False]):
            a,b = b,a
        eds2.append((a, b, w))
    random.shuffle(eds2)
    eds = eds2

print(n, budget)
print(*pop[1:])
for (a, b, w) in eds:
    print(a+1, b+1, w)
