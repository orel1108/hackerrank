#!/usr/bin/env python

n = int(raw_input().strip())
arr = map(int, raw_input().strip().split())
q = int(raw_input().strip())

for _ in xrange(q):
    x, y = map(int, raw_input().strip().split())
    if x == y:
        if arr[x - 1] % 2 == 1:
            print "Odd"
        else:
            print "Even"
    else:
        if arr[x - 1] % 2 == 0 and arr[x] != 0:
            print "Even"
        else:
            print "Odd"

