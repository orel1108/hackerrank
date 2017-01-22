#!/usr/bin/env python

import math

def solve(i_d, i_p):
    D = i_d * i_d + 4 * i_p
    if D < 0:
        return 0
    x = int(math.sqrt(D))
    if x * x != D:
        return 0
    coeff = [(-1, -1), (-1, 1), (1, -1), (1, 1)]
    r = set([])
    for C in coeff:
        b = (C[0] * i_d + C[1] * x) // 2
        r.add((b - C[0] * i_d, b))
    return len(r)
    
t = int(raw_input().strip())
for _ in xrange(t):
    d, p = map(int, raw_input().strip().split())
    if d < 0:
        print 0
    else:
        print solve(d, p)

