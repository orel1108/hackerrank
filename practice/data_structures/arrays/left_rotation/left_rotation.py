#!/usr/bin/env python

n, d = map(int, raw_input().strip().split())
a = map(int, raw_input().strip().split())
for POS in xrange(n):
    print a[(POS + d) % n],
print

