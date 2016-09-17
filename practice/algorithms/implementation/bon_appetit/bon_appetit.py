#!/usr/bin/env python

n, k = map(int, raw_input().strip().split())
c = map(int, raw_input().strip().split())
b = int(raw_input().strip())

total = sum([c[POS] for POS in xrange(n) if POS != k])
if 2 * b <= total:
    print "Bon Appetit"
else:
    print b - total // 2

