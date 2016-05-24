#!/usr/bin/env python

t = int(raw_input().strip())
for _ in xrange(t):
    n, k = map(int, raw_input().strip().split())
    a = []
    for CNT in xrange(n // 2):
        a.append(n - 1 - CNT)
        a.append(CNT)
    a.append(n // 2)
    print a.index(k)

