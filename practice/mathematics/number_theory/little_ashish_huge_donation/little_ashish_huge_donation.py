#!/usr/bin/env python

import bisect

t = int(raw_input().strip())
res = [0]
mx = 10000000000000000L

n = 1
while n * (n + 1) * (2 * n + 1) / 6 <= mx:
    res.append(res[-1] + n * n)
    n += 1

for _ in xrange(t):
    x = int(raw_input().strip())
    print bisect.bisect_right(res, x) - 1

