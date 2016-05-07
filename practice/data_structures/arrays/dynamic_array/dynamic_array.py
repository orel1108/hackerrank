#!/usr/bin/env python

n, q = map(int, raw_input().strip().split())

seq = [[] for _ in range(n)]
last = 0
for _ in xrange(q):
    a, x, y = map(int, raw_input().strip().split())
    pos = (x ^ last) % n
    if a == 1:
        seq[pos].append(y)
    else:
        last = seq[pos][y % len(seq[pos])]
        print last

