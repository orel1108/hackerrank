#!/usr/bin/env python

from fractions import gcd

t = int(raw_input().strip())
for _ in xrange(t):
    x1, y1, x2, y2 = map(int, raw_input().strip().split())
    if x1 == x2:
        if y1 == y2:
            print 0
        else:
            print abs(y1 - y2) - 1
    elif y1 == y2:
        print abs(x1 - x2) - 1
    else:
        t1 = abs(x1 - x2)
        t2 = abs(y1 - y2)
        d = gcd(t1, t2)
        t1 //= d
        if x1 > x2:
            x1, x2 = x2, x1
        print (x2 - x1 - 1) // t1

