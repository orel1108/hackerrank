#!/bin/python

t = int(raw_input().strip())
for _ in range(t):
    n, k = map(int, raw_input().split())
    a = map(int, raw_input().split())
    f = filter(lambda VAL : VAL < 1, a)
    if len(f) < k:
        print "YES"
    else:
        print "NO"

