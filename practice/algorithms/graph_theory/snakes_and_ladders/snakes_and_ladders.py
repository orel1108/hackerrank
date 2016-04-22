#!/usr/bin/env python

def shortest_path(i_graph):
    dists = [1000000 for _ in range(100)]
    dists[0] = 0
    q = [0]
    visited = set([0])
    while q:
        vertex = q.pop(0)
        visited.add(vertex)
        if vertex == 99:
            return dists[vertex]
        for NODE in i_graph[vertex]:
            if NODE not in visited:
                dists[NODE] = min(dists[NODE], dists[vertex] + 1)
                q.append(NODE)
    return -1

t = int(raw_input().strip())
for _ in range(t):
    num_ladders = int(raw_input().strip())
    ladders = {}
    for __ in range(num_ladders):
        s, e = map(int, raw_input().strip().split())
        ladders[s - 1] = e - 1
    
    num_snakes = int(raw_input().strip())
    snakes = {}
    for __ in range(num_snakes):
        s, e = map(int, raw_input().strip().split())
        snakes[s - 1] = e - 1
        
    graph = [set() for _ in range(100)]
    for START in range(100):
        for END in range(START + 1, START + 7):
            if END < 100:
                if END in ladders.keys():
                    graph[START].add(ladders[END])
                elif END in snakes.keys():
                    graph[START].add(snakes[END])
        END = min(START + 6, 99)
        if END not in ladders.keys() and END not in snakes.keys():
            graph[START].add(END)
                
    print shortest_path(graph)

