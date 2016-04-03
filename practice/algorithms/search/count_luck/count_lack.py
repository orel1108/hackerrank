#!/usr/bin/env python

from collections import defaultdict

VISITED = set()
TRACK = defaultdict(int)
def dfs(i_adj_list, i_start, i_end):
    global VISITED, TRACK
    if i_start == i_end:
        return
    VISITED.add(i_start)
    neighbors = []
    for NODE in i_adj_list[i_start]:
        if not NODE in VISITED:
            neighbors.append(NODE)
    if len(neighbors) > 1:
        TRACK[i_start] += 1
    for NODE in neighbors:
        TRACK[NODE] = TRACK[i_start]
        dfs(i_adj_list, NODE, i_end)
        
t = int(raw_input())
for _ in range(t):
    n, m = map(int, raw_input().split())
    adj_list = defaultdict(set)
    forest = []
    start = (0, 0)
    end = (0, 0)
    for ROW_NUM in range(n):
        row = raw_input()
        forest.append(row)
    for ROW_NUM in range(n):
        for COL_NUM in range(m):
            if forest[ROW_NUM][COL_NUM] != 'X':
                if ROW_NUM > 1:
                    if forest[ROW_NUM - 1][COL_NUM] != 'X':
                        adj_list[(ROW_NUM, COL_NUM)].add((ROW_NUM - 1, COL_NUM))
                        adj_list[(ROW_NUM - 1, COL_NUM)].add((ROW_NUM, COL_NUM))
                if ROW_NUM < n - 1:
                    if forest[ROW_NUM + 1][COL_NUM] != 'X':
                        adj_list[(ROW_NUM, COL_NUM)].add((ROW_NUM + 1, COL_NUM))
                        adj_list[(ROW_NUM + 1, COL_NUM)].add((ROW_NUM, COL_NUM))
                if COL_NUM > 1:
                    if forest[ROW_NUM][COL_NUM - 1] != 'X':
                        adj_list[(ROW_NUM, COL_NUM)].add((ROW_NUM, COL_NUM - 1))
                        adj_list[(ROW_NUM, COL_NUM - 1)].add((ROW_NUM, COL_NUM))
                if COL_NUM < m - 1:
                    if forest[ROW_NUM][COL_NUM + 1] != 'X':
                        adj_list[(ROW_NUM, COL_NUM)].add((ROW_NUM, COL_NUM + 1))
                        adj_list[(ROW_NUM, COL_NUM + 1)].add((ROW_NUM, COL_NUM))
                
                if forest[ROW_NUM][COL_NUM] == 'M':
                    start = (ROW_NUM, COL_NUM)
                if forest[ROW_NUM][COL_NUM] == '*':
                    end = (ROW_NUM, COL_NUM)
                        
    k = int(raw_input())
    VISITED = set()
    TRACK = defaultdict(int)
    TRACK[start] = 0
    dfs(adj_list, start, end)
    if k == TRACK[end]:
        print 'Impressed'
    else:
        print 'Oops!'

