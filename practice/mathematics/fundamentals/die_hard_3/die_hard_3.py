#!/usr/bin/env python

t = int(raw_input().strip())
for _ in xrange(t):
    a, b, c = map(int, raw_input().strip().split())
    if a > b:
        b, a = a, b
    if a == c or b == c:
        print 'YES'
    else:
        d = b - a
        while d > 0:
            if d == c:
                print 'YES'
                break
            if d < a:
                d = b - (a - d)
            else:
                d = d - a
        if d == 0:
            print 'NO'

