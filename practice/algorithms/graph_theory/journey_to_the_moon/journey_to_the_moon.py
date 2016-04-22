#!/usr/bin/env python

from collections import defaultdict

graph = []

def init_graph(i_n):
    global graph
    graph = range(i_n)

def find(i_vertex):
    if graph[i_vertex] == i_vertex:
        return i_vertex
    else:
        return find(graph[i_vertex])

def union(i_v1, i_v2):
    global graph
    v1 = find(i_v1)
    v2 = find(i_v2)
    if v1 != v2:
        graph[v1] = v2
        
n, i = map(int, raw_input().strip().split())
init_graph(n)
for _ in range(i):
    a, b = map(int, raw_input().strip().split())
    union(a, b)

d = defaultdict(int)
for V in range(n):
    d[find(V)] += 1

r = 0
for VAL in d.values():
    n -= VAL
    r += VAL * n
print r

