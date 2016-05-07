#!/usr/bin/env python

n = int(raw_input().strip())
d = []
for _ in xrange(n):
    d.append(raw_input().strip())

q = int(raw_input().strip())
for _ in xrange(q):
    s = raw_input().strip()
    print d.count(s)

