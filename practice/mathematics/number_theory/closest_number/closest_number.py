#!/usr/bin/env python

t = int(raw_input().strip())
for _ in xrange(t):
    a, b, x = map(int, raw_input().strip().split())
    p = int(pow(a, b))
    if p < x:
        if 2 * p <= x:
            print 0
        else:
            print x
    else:
        k = p // x
        k *= x
        if 2 * p <= 2 * k + x:
            print k
        else:
            print k + x

