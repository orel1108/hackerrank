#!/usr/bin/env python

import operator

PARENT = dict()
RANK = dict()

def make_set(i_vertice):
    global PARENT, RANK
    PARENT[i_vertice] = i_vertice
    RANK[i_vertice] = 0

def find(i_vertice):
    if PARENT[i_vertice] != i_vertice:
        PARENT[i_vertice] = find(PARENT[i_vertice])
    return PARENT[i_vertice]

def union(i_vertice1, i_vertice2):
    root1 = find(i_vertice1)
    root2 = find(i_vertice2)
    if root1 != root2:
        if RANK[root1] > RANK[root2]:
            PARENT[root2] = root1
        else:
            PARENT[root1] = root2
            if RANK[root1] == RANK[root2]: RANK[root2] += 1

def kruskal(i_graph, i_num_vertices):
    for VERTEX in range(i_num_vertices):
        make_set(VERTEX)

    res_mst = set()
    edges = list(i_graph)
    for EDGE in edges:
        (vertice1, vertice2), weight = EDGE
        if find(vertice1) != find(vertice2):
            union(vertice1, vertice2)
            res_mst.add(EDGE)
    return res_mst

n, m = map(int, raw_input().split())
graph = {}
for _ in range(m):
    v1, v2, w = map(int, raw_input().split())
    v1 -= 1
    v2 -= 1
    if v1 > v2:
        v1, v2 = v2, v1
    if (v1, v2) in graph.keys():
        if w < graph[(v1, v2)]:
            graph[(v1, v2)] = w
    else:
        graph[(v1, v2)] = w

sorted_graph = sorted(sorted(graph.items(), key=lambda x:x[0][0] + x[0][1] + x[1]), key=operator.itemgetter(1))
mst = kruskal(sorted_graph, n)
s = 0
for EDGE in mst:
    s += EDGE[1]
print s

