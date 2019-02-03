#!/usr/bin/python3

import sys
import random
import heapq

default = {
    "n": 60,
    "m": 100,
    "k": 5,
    "width": 300000,
    "mode": "random",
    "maxw": 1000000000,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

specials = []
graph = []
weights = []
S = set()
DIST = []

def dijkstra(start):
    n = len(graph)
    pq = []
    mark = n*[0]
    heapq.heappush(pq,start)
    DIST[start] = 0
    while len(pq) > 0:
        i = heapq.heappop(pq)%n
        if mark[i] == 0:
            mark[i] = 1
            for j2 in range(0,len(graph[i])):
                j = graph[i][j2]
                w = weights[i][j2]
                if DIST[j] == -1 or DIST[j] > w+DIST[i]:
                    DIST[j] = DIST[i]+w
                    heapq.heappush(pq,n*DIST[j]+j)
    return


#  DP to find longest shortest path from "start" that passes through "i"
DP = []
def dp():
    L = []
    n = len(graph)
    for i in range(0,n):
        L.append(DIST[i]*n+i)
    L.sort()
    L.reverse()
    for i2 in L:
        i = i2%n
        DP[i]+=1
        for j2 in range(0,len(graph[i])):
            j = graph[i][j2]
            w = weights[i][j2]
            if DIST[i] == DIST[j]+w:
                DP[j] = max(DP[j],DP[i])

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    m = int(cmdlinearg("m"))
    k = int(cmdlinearg("k"))

    # Only add edges between vertices with |u-v| <= width.
    width = int(cmdlinearg("width"))

    # mode = "random": Place special vertices randomly.
    # mode = "valid": Place special vertices along a shortest path.
    # mode = "almost": Place k-2 valid vertices and 2 at random.
    mode = str(cmdlinearg("mode"))
    maxw = int(cmdlinearg("maxw"))
    
    for i in range(0,n):
        graph.append([])
        weights.append([])

    # Generate a spanning tree
    for i in range(1,n):
        j = i-random.randint(1,min(width,i))
        j = max(0,j)
        graph[i].append(j)
        graph[j].append(i)
        w = random.randint(1,maxw)
        weights[i].append(w)
        weights[j].append(w)
        S.add(i*n+j)
        S.add(j*n+i)

    m2 = m-n+1

    # Add more edges
    lim = 1000
    for i in range(0,m2):
        a = random.randint(1,n-1)
        b = a-random.randint(1,min(width,a))
        b = max(b,0)
        attempts = 0
        while a*n+b in S:
            a = random.randint(1,n-1)
            b = a-random.randint(1,width)
            b = max(b,0)
            attempts += 1
            if attempts > lim:
                break
        if attempts > lim:
            break
        w = random.randint(1,maxw)
        graph[a].append(b)
        graph[b].append(a)
        weights[a].append(w)
        weights[b].append(w)
        S.add(a*n+b)
        S.add(b*n+a)

    if mode == "random":
        specials = random.sample(range(0,n),k)
    else:
        # Find shortest distances from a random starting point "start".
        # Then, find a shortest path "path" of appropriate length.
        for i in range(0,n):
            DIST.append(-1)
            DP.append(0)
        start = random.randint(0,n-1)
        dijkstra(start)
        dp()
        path = []
        while True:
            permutation = list(range(0,len(graph[start])))
            random.shuffle(permutation)
            found = 0
            path.append(start)
            best_length = -1
            nex = -1
            for i in permutation:
                a = graph[start][i]
                w = weights[start][i]

                # This condition checks if edge "start->a" is part of
                # some shortest path.
                if DIST[a] == DIST[start]+w:
                    temp = max(DP[a],k-len(path))
                    if temp > best_length:
                        nex = a
                        found = 1
                        best_length = temp
            if found == 0:
                break
            else:
                start = nex
        if mode == "almost":
            specials = random.sample(path,min(k-2,len(path)))
            for i in range(0,2):
                extra = random.randint(0,n-1)
                while extra in specials:
                    extra = random.randint(0,n-1)
                specials.append(extra)
            random.shuffle(specials)
        else:
            specials = random.sample(path,min(k,len(path)))
            
    edges = []
    for i in range(0,n):
        for j in range(0,len(graph[i])):
            j2 = graph[i][j]
            if j2 > i:
                edges.append([i+1,j2+1,weights[i][j]])

    randomize = 1
    if randomize == 1:
        # Permute vertices and shuffle everything
        permutation = list(range(1,n+1))
        random.shuffle(permutation)
        for i in range(0,len(specials)):
            specials[i] = permutation[specials[i]]-1
        random.shuffle(specials)
        for i in range(0,len(edges)):
            edges[i][0] = permutation[edges[i][0]-1]
            edges[i][1] = permutation[edges[i][1]-1]
        random.shuffle(edges)
    
    print(n,len(edges),len(specials))
    for i in range(0,len(specials)):
        ends = " "
        if i == len(specials)-1:
            ends = "\n"
        print(specials[i]+1, end = ends)
    
    for i in edges:
        print(i[0],i[1],i[2])
    
    


if __name__ == "__main__":
    main()

