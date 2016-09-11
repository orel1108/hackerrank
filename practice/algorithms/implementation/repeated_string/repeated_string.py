#!/usr/bin/env python

s = raw_input().strip()
n = int(raw_input().strip())
q, r = divmod(n, len(s))

cnt_a = s.count('a')
print q * cnt_a + s[:r].count('a')

