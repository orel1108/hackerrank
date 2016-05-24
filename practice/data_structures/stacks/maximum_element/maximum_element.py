#!/usr/bin/env python

sm = []

n = int(raw_input().strip())
for _ in xrange(n):
    p = map(int, raw_input().strip().split())
    if p[0] == 1:
        if sm:
            m = sm[-1]
            sm.append(max(p[1], m))
        else:
            sm.append(p[1])
    elif p[0] == 2:
        if sm:
            sm.pop()
    else:
        print sm[-1]

