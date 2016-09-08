#!/usr/bin/env python

n, k = map(int, raw_input().strip().split())
t = map(int, raw_input().strip().split())

res, curr_page = 0, 1
for Ti in t:
    for POS in xrange(1, Ti + 1):
        if POS == curr_page:
            res += 1
        if POS == Ti or POS % k == 0:
            curr_page += 1
print res

