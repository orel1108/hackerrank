#!/usr/bin/env python

from itertools import combinations

s, k = raw_input().strip().split()
for n in range(1, int(k) + 1):
    for COMB in combinations(sorted(s), n):
        print "".join(COMB)

