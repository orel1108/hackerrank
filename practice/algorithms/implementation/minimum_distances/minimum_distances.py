#!/usr/bin/env python

from collections import defaultdict

n = int(raw_input().strip())
a = map(int, raw_input().strip().split())

positions = defaultdict(set)
for POS in xrange(n):
    positions[a[POS]].add(POS)
    
res = n
for POS_SET in positions.values():
    if len(POS_SET) > 1:
        res = min(res, max(POS_SET) - min(POS_SET))
print res if res < n else -1

