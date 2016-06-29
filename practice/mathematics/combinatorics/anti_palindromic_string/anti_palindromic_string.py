#!/usr/bin/env python

MOD = 10 ** 9 + 7

t = int(raw_input().strip())
for _ in xrange(t):
    n, m = map(int, raw_input().strip().split())
    if n == 1:
        print m
    elif n == 2:
        print m * (m - 1) % MOD
    else:
        total = pow(m - 2, n - 2, MOD)
        res = total * m * (m - 1)
        print res % MOD

