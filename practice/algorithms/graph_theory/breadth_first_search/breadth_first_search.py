#!/usr/bin/env python

from Queue import Queue

def bfs(i_graph, i_start, i_n):
    visited = set()
    visited.add(i_start)
    q = Queue()
    q.put(i_start)
    distances = [0 for _ in range(i_n)]
    while not q.empty():
        vertex = q.get()
        for VERTEX in i_graph[vertex]:
            if VERTEX not in visited:
                distances[VERTEX] = distances[vertex] + 1
                q.put(VERTEX)
                visited.add(VERTEX)
    return distances
                
t = int(raw_input().strip())
for _ in range(t):
    n, m = map(int, raw_input().strip().split())
    graph = [set() for _ in range(n)]
    for __ in range(m):
        v, w = map(int, raw_input().split())
        graph[v - 1].add(w - 1)
        graph[w - 1].add(v - 1)
    s = int(raw_input())
    d = bfs(graph, s - 1, n)
    for CNT in range(n):
        if CNT != s - 1:
            if d[CNT] == 0:
                print -1,
            else:
                print d[CNT] * 6,
    print

