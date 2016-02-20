#!/usr/bin/env python

s = list(raw_input().strip())
n, c = raw_input().strip().split()
s[int(n)] = c
print ''.join(s)

