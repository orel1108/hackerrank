#!/bin/python

import sys

t = int(raw_input().strip())
for _ in xrange(t):
    b, w = map(int, raw_input().strip().split())
    x, y, z = map(int, raw_input().strip().split())
    if x + z < y:
        print x * (b + w) + z * w
    elif y + z < x:
        print y * (b + w) + z * b
    else:
        print x * b + y * w
