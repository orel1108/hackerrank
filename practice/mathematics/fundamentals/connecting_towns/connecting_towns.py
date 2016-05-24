#!/usr/bin/env python

t = int(raw_input().strip())
for _ in xrange(t):
    n = int(raw_input().strip())
    nl = map(int, raw_input().strip().split())
    print reduce(lambda x, y: (x * y) % 1234567, nl, 1)

