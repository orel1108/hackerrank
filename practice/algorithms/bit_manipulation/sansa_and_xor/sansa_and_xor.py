#!/usr/bin/env python

t = int(raw_input().strip())
for _ in xrange(t):
    n = int(raw_input().strip())
    a = map(int, raw_input().strip().split())
    if n % 2 == 0:
        print 0
    else:
        r = 0
        for cnt in xrange(0, n, 2):
            r ^= a[cnt]
        print r

