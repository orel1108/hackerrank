#!/usr/bin/env python

tn, tn_1, n = map(int, raw_input().strip().split())
tn_2 = 0
for _ in xrange(n - 2):
    tn_2 = tn_1 * tn_1 + tn
    tn = tn_1
    tn_1 = tn_2
print tn_2

