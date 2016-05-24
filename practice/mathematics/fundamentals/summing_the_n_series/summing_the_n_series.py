#!/usr/bin/env python

t = int(raw_input().strip())
for _ in xrange(t):
    n = int(raw_input().strip())
    p = n % 1000000007
    print (p * p) % 1000000007

