#!/usr/bin/env python

from itertools import product

K, M = map(int, raw_input().strip().split())
d = []

for _ in range(K):
    row = map(int, raw_input().strip().split())
    d.append(row[1:])

MAX_SUM = 0
for T in product(*d):
    tmp = sum(map(lambda x: x * x, T)) % M
    if tmp >= MAX_SUM:
        MAX_SUM = tmp
print MAX_SUM

