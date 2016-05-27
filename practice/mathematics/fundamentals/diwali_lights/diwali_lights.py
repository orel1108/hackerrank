#!/usr/bin/env python

t = int(raw_input().strip())
for _ in xrange(t):
    val = int(raw_input().strip())
    print pow(2, val, 100000) - 1

