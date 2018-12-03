#!/usr/bin/env python3

import sys
import random

sys.setrecursionlimit(10000000)

def cmdlinearg(name, default=None):
	for arg in sys.argv:
		if arg.startswith(name + "="):
			return arg.split("=")[1]
	assert default is not None, name
	return default

 
random.seed(int(cmdlinearg('seed', sys.argv[-1])))

n = int(cmdlinearg('n'))
m = int(cmdlinearg('m', default=n))
mode = cmdlinearg('mode')
max_cap = int(cmdlinearg('maxc', 10**5))

def permute(edges,keepRoot=False):
	renumbering = list(range(n))
	random.shuffle(renumbering)
	if keepRoot:
		rootIndex = renumbering.index(0)
		renumbering[rootIndex], renumbering[0] = renumbering[0], renumbering[rootIndex]

	new_edges = [[] for _ in range(n)]
	for i in range(n):
		for (j,w) in edges[i]:
			new_edges[renumbering[i]].append((renumbering[j],w))
	return new_edges

def add_weights(edges):	
	for neighbours in edges:
		if len(neighbours) == 0:
			continue
		tot_weight = 0
		for j in range(0,len(neighbours)-1):
			weight = 0
			if tot_weight < 100: 
				weight = random.randint(1,100-tot_weight-(len(neighbours)-j-1))
			neighbours[j] = (neighbours[j][0],weight)
			tot_weight += weight
		neighbours[len(neighbours)-1] = (neighbours[len(neighbours)-1][0], 100-tot_weight)

def get_cMax(edges):
	revEdge = [[] for i in range(n)]
	for node,neighbours in enumerate(edges):
		for edge in neighbours:
			revEdge[edge[0]].append((node,edge[1]))

	cMax = [0 for i in range(n)]
	output = [-1 for i in range(n)]

	def getOutput(v):
		if output[v] != -1:
			return output[v]
		if not revEdge[v]:
			cMax[v] = random.randint(1, max_cap)
			output[v] = cMax[v]
		else:
			val = 0.0
			for u in revEdge[v]:
				val += getOutput(u[0])*u[1]/100.0

			#Making sure proper margin:
			while True:
				cMax[v] = random.randint(1, max_cap)
				if abs(val - cMax[v]) > 1e-4: 
					break

			output[v] = min(cMax[v],val)
		return output[v]

	for i in range(n):
		getOutput(i)

	return cMax



def get_random_edges():
	edges_no_w = set()
	edges = [[] for _ in range(n)]
	while len(edges_no_w) < m:
		a = random.randrange(n)
		b = random.randrange(n)
		a,b = min(a,b), max(a,b)
		if a == b:
			continue
		if (a, b) in edges_no_w:
			continue
		edges_no_w.add((a, b))
		edges[a].append((b, 0))

	add_weights(edges)
	return edges

def get_components():
	comps = n - m
	components = [[i] for i in range(comps)]
	for i in range(comps, m):
		components[random.randrange(comps)].append(i)
	return components

def get_deep_tree_edges():
	edges = [[] for _ in range(n)]
	def rec(v, dn, up):
		if dn >= up:
			return
		children = random.choice([1,1,1,1,2,2,3])
		for i in range(children - 1):
			edges[v].append((dn,0))
			childSize = min(up-dn, random.choice([1,1,2,3]))
			rec(dn, dn+1, dn+childSize)
			dn += childSize
			if dn >= up:
				return
		edges[v].append((dn, 0))
		rec(dn, dn+1, up)

	rec(0, 1, n)

	add_weights(edges)
	return edges

def get_shallow_tree_edges():
	edges = [[] for _ in range(n)]
	for i in range(1, n):
		edges[random.randrange(i)].append((i,0))
	add_weights(edges)
	return edges


def get_line_edges():
	components = get_components()
	edges = [[] for _ in range(n)]
	for component in components:
		for i in range(0,len(component)-1):
			a = component[i]
			b = component[i+1]
			edges[a].append((b, 0))
	add_weights(edges)
	return edges


def print_input(edges):
	cMax = get_cMax(edges)
	print(n)
	for cap, adj in zip(cMax, edges):
		tokens = []
		tokens.append(cap)
		tokens.append(len(adj))
		for (neighbour, weight) in adj:
			tokens.append(neighbour+1)
			tokens.append(weight)
		print(*tokens)

if mode == 'line':
	print_input(permute(get_line_edges()))

if mode == 'deepTree':
	print_input(permute(get_deep_tree_edges(), keepRoot=True))

if mode == 'shallowTree':
	print_input(permute(get_shallow_tree_edges(), keepRoot=True))

if mode == 'standard':
	print_input(permute(get_random_edges()))

if mode == 'sorted':
	print_input(get_random_edges())
