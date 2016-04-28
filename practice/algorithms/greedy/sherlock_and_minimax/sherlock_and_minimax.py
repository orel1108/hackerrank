#!/usr/bin/env python

n = int(raw_input().strip())
a = sorted(map(int, raw_input().strip().split()))
p, q = map(int, raw_input().strip().split())

candidates = [p, q]
for CNT in range(n - 1):
    half = (a[CNT] + a[CNT + 1]) // 2
    if half >= p and half <= q:
        candidates.append(half)

max_dist = 0
M = 0
for VAL in candidates:
    min_dist = abs(a[0] - VAL)
    for POS in range(len(a)):
        if abs(a[POS] - VAL) < min_dist:
            min_dist = abs(a[POS] - VAL)
    if min_dist > max_dist:
        max_dist = min_dist
        M = VAL
print M

