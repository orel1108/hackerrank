#!/usr/bin/env python

from __future__ import division
from math import factorial

n = int(raw_input().strip())
s = raw_input().strip().split()

t = 0
for C in s:
    if C == 'a':
        t += 1

k = int(raw_input().strip())
if k + t > n:
    print 1.0
else:
    r = 1.0 - factorial(n - t) * factorial(n - k) / (factorial(n) * factorial(n - t - k))
    print r

