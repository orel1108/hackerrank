#!/usr/bin/env python

n = int(raw_input().strip())
a = map(int, raw_input().strip().split())
b = map(int, raw_input().strip().split())

if n == 1:
    print 0
else:
    x = set()
    y = set()

    d = set()
    for R in range(n):
        for C in range(n):
            if a[R] == b[C]:
                if R not in x and C not in y:
                    x.add(R)
                    y.add(C)
                    d.add((R, C))
    
    if len(d) == 0:
        print 0
    elif len(x) == n:
        print n - 1
    else:
        print len(d) + 1

