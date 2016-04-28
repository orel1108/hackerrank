#!/usr/bin/env python

import heapq

INF = float("inf")

def dijkstra(i_graph, i_n, i_s):
    dists = [INF for _ in range(i_n)]
    
    q = []
    heapq.heappush(q, (0, i_s))
    dists[i_s] = 0
    
    while q:
        p = heapq.heappop(q)
        vertex = p[1]
        for PAIR in i_graph[vertex]:
            if (dists[vertex] + PAIR[0] < dists[PAIR[1]]):
                dists[PAIR[1]] = dists[vertex] + PAIR[0]
                heapq.heappush(q, (dists[PAIR[1]], PAIR[1]))
    return dists
                
t = int(raw_input().strip())
for _ in range(t):
    n, m, k = map(int, raw_input().strip().split())
    graph = [set() for _ in range(n)]
    
    s1 = 0
    s2 = 0
    l = 0
    for cnt in range(m):
        v1, v2, w = map(int, raw_input().strip().split())
        graph[v1 - 1].add((w, v2 - 1))
        graph[v2 - 1].add((w, v1 - 1))
        if cnt == k - 1:
            s1 = v1 - 1
            s2 = v2 - 1
            l = w
            
    dists1 = dijkstra(graph, n, s1)
    dists2 = dijkstra(graph, n, s2)
    dists = sorted([(dists1[POS], dists2[POS]) for POS in range(n)])
    
    prevx = -1
    prevy = -1
    pairs = []
    for POS in range(n - 1, -1, -1):
        if dists[POS][0] <= prevx and dists[POS][1] <= prevy:
            continue
        prevx = dists[POS][0]
        prevy = dists[POS][1]
        pairs.append(dists[POS])
        
    ans = min(pairs[0][0], pairs[-1][1])
    fans = 0
    
    if pairs[0][0] <= pairs[-1][1]:
        fans = 0
    else:
        fans = l
        
    for POS in range(len(pairs) - 1):
        tmp = (pairs[POS][1] - pairs[POS + 1][0] + l) / 2.0
        val = pairs[POS + 1][0] + tmp
        if val < ans:
            ans = val
            fans = tmp
        elif val == ans:
            fans = min(fans, tmp)
            
    print '%.5f %.5f' % (round(fans, 5), round(ans, 5))

