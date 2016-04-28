#!/usr/bin/env python

n = int(raw_input().strip())
h = map(int, raw_input().strip().split())

s = h[0]
for cnt in range(1, n):
    s = 2 * s + h[cnt]
if s % (2 ** n) == 0:
    print s // 2 ** n
else:
    print s // 2 ** n + 1

