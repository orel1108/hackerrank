#!/usr/bin/env python

n, m = map(int, raw_input().strip().split())

s = 0
for _ in xrange(m):
    vals = map(int, raw_input().strip().split())
    s += ((vals[1] - vals[0] + 1) * vals[2])
print s // n

