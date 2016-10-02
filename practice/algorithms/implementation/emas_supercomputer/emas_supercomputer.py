#!/usr/bin/env python

def find_plus(grid, row, col):
    n = len(grid)
    m = len(grid[0])
    k = 0
    d = 0
    sizes = []
    while True:
        neigbors = [(row - k, col), (row + k, col), (row, col - k), (row, col + k)]
        for NEIGHBOR in neigbors:
            if -1 < NEIGHBOR[0] and NEIGHBOR[0] < n and -1 < NEIGHBOR[1] and NEIGHBOR[1] < m:
                if grid[NEIGHBOR[0]][NEIGHBOR[1]] != 'G':
                    return sizes
            else:
                return sizes
        k += 1
        d += 1
        sizes.append(d)

def intersects(plus1, plus2):
    s1 = set()
    x = plus1[1][0]
    y = plus1[1][1]
    for k in range(plus1[0]):
        s1.add((x - k, y))
        s1.add((x + k, y))
        s1.add((x, y - k))
        s1.add((x, y + k))
        
    s2 = set()
    x = plus2[1][0]
    y = plus2[1][1]
    for k in range(plus2[0]):
        s2.add((x - k, y))
        s2.add((x + k, y))
        s2.add((x, y - k))
        s2.add((x, y + k))
        
    return bool(s1.intersection(s2))

n, m = map(int, raw_input().split())
grid = []
for _ in range(n):
    grid.append(list(raw_input()))

pluses = []
for ROW in range(n):
    for COL in range(m):
        if grid[ROW][COL] == 'G':
            d = find_plus(grid, ROW, COL)
            for D in d:
                pluses.append((D, (ROW, COL)))

r = 0            
for N in range(len(pluses)):
    for M in range(N + 1, len(pluses)):
        if not intersects(pluses[N], pluses[M]):
            d = (4 * (pluses[N][0] - 1) + 1) * (4 * (pluses[M][0] - 1) + 1)
            if d > r:
                r = d
print r

