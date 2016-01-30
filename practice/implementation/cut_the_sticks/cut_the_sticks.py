#!/bin/python
from collections import Counter

n = int(raw_input().strip())
arr = map(int,raw_input().strip().split(' '))
c = Counter(arr)

sticks = sorted(c.items())
s = 0
for PAIR in sticks:
    print n - s
    s += PAIR[1]
