#!/usr/bin/env python

n = input()
s = set()
for _ in range(n):
    stamp = raw_input().strip()
    s.add(stamp)
print len(s)

