#!/usr/bin/env python

def prim_mst(i_graph, i_s, i_n):
    visited = set([i_s])
    mst = []
    for _ in range(i_n - 1):
        m = 10 ** 7
        for VERT in visited:
            for PAIR in i_graph[VERT]:
                if PAIR[0] not in visited:
                    w = PAIR[1]
                    if w < m:
                        m = w
                        v = PAIR[0]
                        e = (VERT, PAIR[0], m)
        visited.add(v)
        mst.append(e)
    return mst

n, m = map(int, raw_input().strip().split())
graph = [set() for _ in range(n)]

for _ in range(m):
    x, y, w = map(int, raw_input().strip().split())
    graph[x - 1].add((y - 1, w))
    graph[y - 1].add((x - 1, w))
    
s = int(raw_input().strip())

mst = prim_mst(graph, s - 1, n)
res = 0
for E in mst:
    res += E[2]
print res

