#!/usr/bin/env python

import math

def num_divisors(i_n):
    cnt = 0
    sn = int(math.sqrt(i_n))
    for P in range(1, sn + 1):
        if i_n % P == 0:
            cnt += 2
    if sn * sn == i_n:
        cnt -= 1
    return cnt

t = int(raw_input().strip())
for _ in xrange(t):
    n = int(raw_input())
    if n % 2 == 0:
        print num_divisors(n // 2)
    else:
        print 0

