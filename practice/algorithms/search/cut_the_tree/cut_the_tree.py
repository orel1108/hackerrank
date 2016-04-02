#!/usr/bin/env python

from Queue import Queue

def bfs(i_graph, i_start, i_n):
    visited = set()
    visit_order = []
    parent = [-1 for _ in range(i_n)]
    q = Queue()
    q.put(i_start)
    while not q.empty():
        NODE = q.get()
        if NODE not in visited:
            visited.add(NODE)
            visit_order.append(NODE)
            for VERT in i_graph[NODE]:
                if VERT not in visited:
                    q.put(VERT)
                    parent[VERT] = NODE
    return parent, visit_order

def make_graph(i_edges, i_n):
    r_list = [set([]) for _ in range(i_n)]
    for EDGE in i_edges:
        r_list[EDGE[0]].add(EDGE[1])
        r_list[EDGE[1]].add(EDGE[0])
    return r_list
            
n = int(raw_input())
w = map(int, raw_input().split())

total = sum(w)
edges = []
for _ in range(n - 1):
    v1, v2 = map(int, raw_input().split())
    edges.append((v1 - 1, v2 - 1))

graph = make_graph(edges, n)
parent, visit_order = bfs(graph, 0, n)

sums = [0 for _ in range(n)]
for VERT in reversed(visit_order):
    sums[VERT] += w[VERT]
    c = VERT
    p = parent[c]
    if p != -1:
        sums[p] += sums[VERT]
        
m = total
for CNT in range(n):
    m = min(m, abs(2 * sums[CNT] - total))
    
print m

