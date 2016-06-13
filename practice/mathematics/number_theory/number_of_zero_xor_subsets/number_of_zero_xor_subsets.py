#!/usr/bin/env python

def count(i_n):
    d = pow(2, i_n, 1000000006) - i_n
    return pow(2, d % 1000000006, 1000000007)

t = int(raw_input().strip())
for _ in xrange(t):
    n = int(raw_input().strip())
    print count(n)

