#!/usr/bin/env python

t = int(raw_input().strip())
for _ in xrange(t):
    n = int(raw_input().strip())
    a = map(int, raw_input().strip().split())
    
    m = min(a)
    if m == 1:
        print "YES"
    else:
        val = 2
        while val < m + 1:
            pos = 0
            while pos < n:
                if a[pos] % val != 0:
                    break
                pos += 1
            if pos == n:
                print "NO"
                break
            val += 1
        if val == m + 1:
            print "YES"

