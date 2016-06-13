#!/usr/bin/env python

import math

t = int(raw_input().strip())
for _ in xrange(t):
    n = int(raw_input().strip())
    a = int(math.sqrt(n))
    if a * a > n:
        a -= 1
    if a % 2 == 0:
        print 'even'
    else:
        print 'odd'

