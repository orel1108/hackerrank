#!/usr/bin/env python

from collections import defaultdict

n = int(raw_input().strip())
c = map(int, raw_input().strip().split())

counter = defaultdict(int)

for COL in c:
    counter[COL] += 1

print (n - sum(map(lambda x: x % 2, counter.values()))) // 2

