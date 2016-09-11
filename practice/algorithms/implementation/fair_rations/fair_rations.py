#!/usr/bin/env python

n = int(raw_input().strip())
b = map(int,raw_input().strip().split())

res = 0
for POS in xrange(n - 1):
    if b[POS] % 2 == 1:
        b[POS + 1] += 1
        res += 2
if b[n - 1] % 2 == 0:
    print res
else:
    print "NO"

