#!/usr/bin/env python

from fractions import gcd

t = int(raw_input().strip())
for _ in xrange(t):
    n, m = map(int, raw_input().strip().split())
    d = pow(10, n, 9 * m)
    d -= 1
    if d < 0:
        d += 9 * m
    print d // 9

