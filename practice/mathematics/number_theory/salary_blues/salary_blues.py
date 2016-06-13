#!/usr/bin/env python

from fractions import gcd

def normalize(i_a):
    d = i_a[0]
    for CNT in range(1, len(i_a)):
        d = gcd(d, i_a[CNT])
        if d == 1:
            break
    return d

n, q = map(int, raw_input().strip().split())
a = map(int, raw_input().split())

if min(a) == max(a):
    for _ in xrange(q):
        k = int(raw_input().strip())
        print a[0] + k
else:    
    d = normalize(a)
    for _ in xrange(q):
        k = int(raw_input().strip())
        if k == 0:
            print d
        else:
            print gcd(d, k)

