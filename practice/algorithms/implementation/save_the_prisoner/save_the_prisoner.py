#!/usr/bin/env python

t = int(raw_input().strip())
for _ in xrange(t):
    n, m, s = map(int, raw_input().strip().split())
    res = (m + s - 1) % n
    print n if res == 0 else res

