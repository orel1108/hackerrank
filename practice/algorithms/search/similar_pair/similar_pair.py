#!/usr/bin/env python

def Get(i_pos, i_b):
    i_pos += 1
    res = 0
    while i_pos:
        res += i_b[i_pos - 1]
        i_pos -= (i_pos & -i_pos)
    return res

def Set(i_pos, i_b, i_n, i_val):
    i_pos += 1
    while i_pos <= i_n:
        i_b[i_pos - 1] += i_val
        i_pos += (i_pos & -i_pos)

def dfs(i_graph, i_start, i_n, i_t):
    pairs = 0
    stack = [i_start]
    colors = [0 for _ in range(i_n)]
    ancestors = [0 for _ in range(i_n)]
    while stack:
        NODE = stack[-1]
        if colors[NODE] == 0:
            colors[NODE] = 1
        else:
            colors[NODE] = 2
            stack.pop()
        
        v = Get(NODE, ancestors)
        if NODE > 0:
            v -= Get(NODE - 1, ancestors)
        Set(NODE, ancestors, i_n, 1 - v)
        
        for VERT in i_graph[NODE]:
            if colors[VERT] == 0:
                stack.append(VERT)
        if colors[NODE] == 2:
            left = max(0, NODE - i_t)
            right = min(i_n, NODE + i_t)
            
            v = Get(NODE, ancestors)
            if NODE > 0:
                v -= Get(NODE - 1, ancestors)
            if v > 0 and right < i_n - 1:
                right += 1
            Set(NODE, ancestors, i_n, -v)
            
            B = Get(right - 1, ancestors)
            if left > 0:
                B -= Get(left - 1, ancestors)
            pairs += B
    return pairs

n, t = map(int, raw_input().split())
edges = []
childs = set([])
graph = [set() for _ in range(n)]
for _ in range(n - 1):
    v1, v2 = map(int, raw_input().split())
    childs.add(v2 - 1)
    graph[v1 - 1].add(v2 - 1)
    
root = (n - 1) * n // 2 - sum(childs)

pairs = dfs(graph, root, n, t)
print pairs

