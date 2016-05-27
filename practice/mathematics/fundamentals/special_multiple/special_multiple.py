#!/usr/bin/env python

def solve(i_value):
    for I in xrange(1, 6000):
        s = 0
        for J in xrange(13):
            tmp = 9 if (I & (1 << J)) > 0 else 0 
            s += (tmp * (10 ** J))
        if s % i_value == 0:
            return s
    return 0

t = int(raw_input().strip())
for _ in xrange(t):
    n = int(raw_input().strip())
    print solve(n)

