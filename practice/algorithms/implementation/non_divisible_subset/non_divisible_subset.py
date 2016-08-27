#!/usr/bin/env python

n, k = map(int, raw_input().strip().split())
a = map(int, raw_input().strip().split())


b = [0 for _ in xrange(k)]
for POS in xrange(n):
    b[a[POS] % k] += 1
    
res = 0
if b[0] > 0:
    res = 1
    
for POS in xrange(1, k // 2 + 1):
    res += max(b[POS], b[k - POS])

if k % 2 == 0:
    if b[k // 2] > 1:
        res -= b[k // 2] - 1
print res

