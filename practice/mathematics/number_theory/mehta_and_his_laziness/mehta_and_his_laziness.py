#!/usr/bin/env python

import math
from fractions import gcd

SQUARES = map(lambda x: x * x, range(2, 1001, 2))

def num_divisors(i_n):
    cnt = 0
    s = int(math.sqrt(i_n))
    for VAL in xrange(1, s + 1):
        if i_n % VAL == 0:
            cnt += 2
    if s * s == i_n:
        cnt -= 1
    return cnt - 1

def even_squares_divs(i_n):
    cnt = 0
    for VAL in SQUARES:
        if VAL >= i_n:
            break
        if i_n % VAL == 0:
            cnt += 1
    return cnt

t = int(raw_input().strip())
for _ in xrange(t):
    n = int(raw_input().strip())
    ne = even_squares_divs(n)
    if ne == 0:
        print 0
    else:
        nd = num_divisors(n)
        d = gcd(nd, ne)
        print '%d/%d' % (ne // d, nd // d)

