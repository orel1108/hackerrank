#!/usr/bin/env python

from fractions import gcd

t = int(raw_input().strip())
for _ in xrange(t):
    l, b = map(int, raw_input().strip().split())
    g = gcd(l, b)
    print l * b / (g * g)

