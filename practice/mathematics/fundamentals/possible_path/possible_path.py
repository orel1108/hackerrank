#!/usr/bin/env python

from fractions import gcd

t = int(raw_input().strip())
for _ in xrange(t):
    a, b, x, y = map(int, raw_input().strip().split())
    t = gcd(a, b)
    s = gcd(x, y)
    if s == t:
        print 'YES'
    else:
        print 'NO'

