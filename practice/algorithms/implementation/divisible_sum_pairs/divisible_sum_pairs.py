#!/usr/bin/env python

n, k = map(int, raw_input().strip().split())
a = map(int, raw_input().strip().split())
r = 0
for I in xrange(n):
    for J in xrange(I + 1, n):
        if (a[I] + a[J]) % k == 0:
            r += 1
print r

