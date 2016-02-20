#!/usr/bin/env python

from collections import defaultdict

d = defaultdict(list)
n, m = map(int, raw_input().strip().split())

for CNT in range(n):
    w = raw_input().strip()
    d[w].append(CNT + 1)
    
for _ in range(m):
    w = raw_input().strip()
    if d.has_key(w):
        for POS in d[w]:
            print POS,
        print
    else:
        print -1

