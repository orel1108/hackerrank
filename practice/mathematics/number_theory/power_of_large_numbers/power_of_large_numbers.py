#!/usr/bin/env python

t = int(raw_input().strip())
for _ in xrange(t):
    a, b = map(int, raw_input().strip().split())
    a %= 1000000007
    print pow(a, b, 1000000007)

