#!/usr/bin/env python

from itertools import permutations

s = raw_input().strip().split()
k = int(s[1])
p = list(permutations(sorted(s[0]), k))

for P in p:
    st = ''
    for C in P:
        st += C
    print st

