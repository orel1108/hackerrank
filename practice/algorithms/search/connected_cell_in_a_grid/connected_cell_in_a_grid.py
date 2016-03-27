#!/usr/nim/env python

from itertools import product

def find_neigbors(i_matrix, i_row_num, i_col_num, i_m, i_n):
    neigbors = set([])
    for NEIGHBOR in product([i_row_num - 1, i_row_num, i_row_num + 1], [i_col_num - 1, i_col_num, i_col_num + 1]):
        if NEIGHBOR[0] in range(i_m) and NEIGHBOR[1] in range(i_n):
            if NEIGHBOR != (i_row_num, i_col_num) and i_matrix[NEIGHBOR[0]][NEIGHBOR[1]] == '1':
                neigbors.add(NEIGHBOR)
    return neigbors

def dfs(i_graph, i_start, visited=set()):
    visited.add(i_start)
    for VERT in i_graph[i_start]:
        if VERT not in visited:
            dfs(i_graph, VERT, visited)

m = int(raw_input())
n = int(raw_input())
matrix = []
for _ in range(m):
    matrix.append(raw_input().split())

graph = {}
vertices = set()
for ROW_NUM in range(m):
    for COL_NUM in range(n):
        if matrix[ROW_NUM][COL_NUM] == '1':
            vertices.add((ROW_NUM, COL_NUM))
            neigbors = find_neigbors(matrix, ROW_NUM, COL_NUM, m, n)
            graph[(ROW_NUM, COL_NUM)] = set(neigbors)

reg_size = 0
while vertices:
    visited = set()
    start = vertices.pop()
    dfs(graph, start, visited)
    if len(visited) > reg_size:
        reg_size = len(visited)
    vertices -= visited
print reg_size

