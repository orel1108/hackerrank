#!/usr/bin/env python

from __future__ import division

x1, v1, x2, v2 = map(int, raw_input().strip().split())
if v1 != v2:
    t = (x1 - x2) / (v2 - v1)
    if t >= 0 and t == int(t):
        print "YES"
    else:
        print "NO"
elif x1 == x2:
    print "YES"
else:
    print "NO"

