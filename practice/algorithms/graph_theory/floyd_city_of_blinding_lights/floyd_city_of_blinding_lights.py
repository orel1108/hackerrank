#!/usr/bin/env python

def floyd(i_graph, i_n):
    dists = [[float("inf") for _ in range(i_n)] for __ in range(i_n)]
    for V in range(i_n):
        dists[V][V] = 0
    
    for EDGE in i_graph.keys():
        dists[EDGE[0]][EDGE[1]] = i_graph[EDGE]
        
    for K in range(i_n):
        for I in range(i_n):
            for J in range(i_n):
                dists[I][J] = min(dists[I][J], dists[I][K] + dists[K][J])
    return dists

n, m = map(int, raw_input().strip().split())
graph = {}
for _ in range(m):
    x, y, w = map(int, raw_input().strip().split())
    graph[(x - 1, y - 1)] = w
    
dists = floyd(graph, n)

q = int(raw_input().strip())
for _ in range(q):
    a, b = map(int, raw_input().strip().split())
    if dists[a - 1][b - 1] < float("inf"):
        print dists[a - 1][b - 1]
    else:
        print -1

