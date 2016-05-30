#!/usr/bin/env python

import math

def is_square(i_n):
    return i_n == int(math.sqrt(i_n)) ** 2

t = int(raw_input().strip())
for _ in xrange(t):
    n = int(raw_input().strip())
    a = n ** 2
    print 'IsFibo' if is_square(5 * a - 4) or is_square(5 * a + 4) else 'IsNotFibo'

