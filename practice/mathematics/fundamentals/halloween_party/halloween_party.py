#!/usr/bin/env python

t = int(raw_input().strip())
for _ in xrange(t):
    n = int(raw_input().strip())
    if n == 0 or n == 1:
        print 0
    else:
        if n % 2 == 0:
            print (n // 2) ** 2
        else:
            print (n // 2) * ((n + 1) // 2) 

