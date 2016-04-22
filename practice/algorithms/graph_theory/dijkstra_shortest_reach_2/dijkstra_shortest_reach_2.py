#!/usr/bin/env python

from heapq import heappush, heappop
import sys

MAX_DIST = sys.maxint

def Dijkstra(i_graph, i_start, i_n):
    A = [None for _ in range(i_n)]
    queue = [(0, i_start)]
    while queue:
        path_len, v = heappop(queue)
        if A[v] is None: # v is unvisited
            A[v] = path_len
            for w, edge_len in graph[v]:
                if A[w] is None:
                    heappush(queue, (path_len + edge_len, w))

    return [-1 if x is None else x for x in A] 
    
                
t = int(raw_input().strip())
for _ in range(t):
    n, m = map(int, raw_input().strip().split())
    graph = [set() for _ in range(n)]
    dists = {}
    for __ in range(m):
        v1, v2, w = map(int, raw_input().split())
        v1 -= 1
        v2 -= 1
        graph[v1].add((v2, w))
        graph[v2].add((v1, w))
    s = int(raw_input())
    d = Dijkstra(graph, s - 1, n)
    for VAL in d:
        if VAL != 0:
            print VAL,
    print

