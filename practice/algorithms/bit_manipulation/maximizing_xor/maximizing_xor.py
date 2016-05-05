#!/usr/bin/env python

def max_xor(i_l, i_r):
    maxv = 0
    for i in xrange(i_l, i_r + 1):
        for j in xrange(i_l, i):
            x = i ^ j
            if x > maxv:
                maxv = x
    return maxv

l = int(raw_input().strip())
r = int(raw_input().strip())
print max_xor(l, r)

