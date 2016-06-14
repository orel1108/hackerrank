#!/usr/bin/env python

from fractions import gcd

def lcm(i_a, i_b):
    return i_a * i_b // gcd(i_a, i_b)

t = int(raw_input().strip())
for _ in xrange(t):
    n = int(raw_input().strip())
    a = map(int, raw_input().strip().split())
    print a[0]
    for CNT in xrange(n - 1):
        print lcm(a[CNT], a[CNT + 1]),
    print a[-1]

