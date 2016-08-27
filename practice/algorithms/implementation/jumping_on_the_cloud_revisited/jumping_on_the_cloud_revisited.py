#!/usr/bin/env python

n, k = map(int, raw_input().strip().split())
cloud = map(int, raw_input().strip().split())

h = n // k
s = 2 if cloud[0] == 1 else 0
e = 100 - h - s

for POS in xrange(1, h):
    e -= 2 * cloud[POS * k]
print e

