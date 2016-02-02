#!/bin/python

def contains(grid, pattern, row, col):
    for ROW in range(len(pattern)):
        for COL in range(len(pattern[0])):
            x = ROW + row
            y = COL + col
            if (x >= len(grid)) or (y >= len(grid[0])):
                return False
            if grid[x][y] != pattern[ROW][COL]:
                return False
    return True

t = int(raw_input().strip())
for _ in range(t):
    R, C = map(int, raw_input().strip().split())
    grid = []
    for __ in range(R):
        grid.append(str(raw_input().strip()))

    r, c = map(int, raw_input().strip().split())
    pattern = []
    for __ in range(r):
        pattern.append(str(raw_input().strip()))
        
    ans = False
    for ROW in range(R):
        for COL in range(C):
            if contains(grid, pattern, ROW, COL):
                ans = True
                break
        if ans:
            break
    if ans:
        print "YES"
    else:
        print "NO"

