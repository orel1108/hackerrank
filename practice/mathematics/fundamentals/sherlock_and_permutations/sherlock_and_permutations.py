#!/usr/bin/env python

from math import factorial

def coeff(i_n, i_m):
    if i_m == 0:
        return 1
    else:
        num = factorial(i_n)
        den = factorial(i_n - i_m) * factorial(i_m)
        return (num / den) % 1000000007

t = int(raw_input().strip())
for _ in xrange(t):
    n, m = map(int, raw_input().strip().split())
    print coeff(n + m - 1, m - 1)

