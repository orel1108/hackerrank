#!/usr/bin/env python

n, m = map(int, raw_input().strip().split())

res = [0 for _ in range(n)]

for _ in range(m):
    L, R, val = map(int, raw_input().strip().split())
    res[L - 1] += val
    if R < n:
        res[R] -= val

val = res[0]
max_val = res[0]
for POS in range(1, n):
    val += res[POS]
    if max_val < val:
        max_val = val
print max_val

