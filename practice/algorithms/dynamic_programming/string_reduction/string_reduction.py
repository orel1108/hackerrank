#!/usr/bin/env python

from collections import Counter

def stringReduction(i_s):
    c = Counter(i_s)
    n = len(s)
    
    if c['a'] == n or c['b'] == n or c['c'] == n:
        return n
    
    if c['a'] % 2 == c['b'] % 2 and c['b'] % 2 == c['c'] % 2:
        return 2
    return 1

t = int(raw_input().strip())
for _ in range(t):
    s = raw_input().strip()
    print stringReduction(s)

