#!/usr/bin/env python

t = int(raw_input().strip())
for _ in xrange(t):
    n, m = map(int, raw_input().strip().split())
    q, r = divmod(n, m)
    res = m * (m - 1) * q // 2
    res += r * (r + 1) // 2
    print res

