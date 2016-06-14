#!/usr/bin/env python

from fractions import gcd

n, m = map(int, raw_input().strip().split())

a = []
for _ in xrange(n):
    row = map(int, raw_input().strip().split())
    a.append(row)

aux = [[[] for _ in xrange(m)] for __ in xrange(n)]
for ROW in xrange(n):
    for COL in xrange(m):
        aux[ROW][COL] = [a[ROW][COL]]
        row_cnt = ROW + 1
        d = a[ROW][COL]
        while row_cnt < n:
            d = gcd(d, a[row_cnt][COL])
            if d == 1:
                break
            aux[ROW][COL].append(d)
            row_cnt += 1

r = 0
for ROW in xrange(n):
    for COL in xrange(m):
        for CNT in xrange(len(aux[ROW][COL]) - 1, -1, -1):
            if (CNT + 1) * (m - COL) < r:
                break
            h = CNT + 1
            col_cnt = COL + 1
            d = aux[ROW][COL][CNT]
            if d > 1:
                w = 1
                while col_cnt < m and CNT < len(aux[ROW][col_cnt]):
                    d = gcd(d, aux[ROW][col_cnt][CNT])
                    if d == 1:
                        break
                    w += 1
                    col_cnt += 1
                if w * h > r:
                    r = w * h
print r

