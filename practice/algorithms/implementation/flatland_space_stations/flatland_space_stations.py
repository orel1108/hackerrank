#!/usr/bin/env python

n, m = map(int, raw_input().strip().split())
c = sorted(map(int, raw_input().strip().split()))

res = max(c[0], n - c[m - 1] - 1)
    
for POS in xrange(1, m):
    res = max(res, (c[POS] - c[POS - 1]) // 2)
print res

