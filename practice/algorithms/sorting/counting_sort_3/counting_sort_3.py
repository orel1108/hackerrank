#!/usr/bin/env python

from collections import Counter

n = int(raw_input().strip())
a = []
for _ in range(n):
    v, s = raw_input().strip().split()
    a.append(int(v))

counter = Counter(a)

s = 0
for VAL in range(100):
    if VAL in counter.keys():
        s += counter[VAL]
    print s,
