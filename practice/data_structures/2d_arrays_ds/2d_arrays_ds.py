#!/usr/bin/env python

arr = []
for _ in xrange(6):
    arr.append(map(int,raw_input().strip().split()))

m = -50
for ROW in range(4):
    for COL in range(4):
        s = sum(arr[ROW][COL:COL + 3]) + sum(arr[ROW + 2][COL:COL + 3]) + arr[ROW + 1][COL + 1]
        if s > m:
            m = s
print m

