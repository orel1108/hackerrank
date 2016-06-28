#!/usr/bin/env python

a, b = map(int, raw_input().strip().split())

c = 2
for _ in xrange(a):
    c = (c * c) % b
print c

