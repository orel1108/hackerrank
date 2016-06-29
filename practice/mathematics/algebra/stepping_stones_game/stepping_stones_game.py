#!/usr/bin/env python

from math import sqrt

t = int(raw_input().strip())
for _ in xrange(t):
    n = int(raw_input().strip())
    k = int(sqrt(2 * n))
    while k * (k + 1) < 2 * n:
        k += 1
    if k * (k + 1) == 2 * n:
        print "Go On Bob", k
    else:
        print "Better Luck Next Time"

