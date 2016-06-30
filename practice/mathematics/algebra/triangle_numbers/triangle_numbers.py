#!/usr/bin/env python

t = int(raw_input().strip())
for _ in xrange(t):
    n = int(raw_input().strip())
    if n % 2 == 1:
        print 2
    elif n % 4 == 0:
        print 3
    else:
        print 4

