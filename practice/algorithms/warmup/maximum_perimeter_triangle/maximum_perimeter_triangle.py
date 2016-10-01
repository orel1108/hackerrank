#!/usr/bin/env python

n = int(raw_input().strip())
l = sorted(map(int, raw_input().strip().split()), reverse=True)
max_perimeter = 0
triangle = []
for POS in xrange(n - 2):
    if l[POS] < l[POS + 1] + l[POS + 2]:
        triangle = [l[POS + 2], l[POS + 1], l[POS]]
        break
if triangle:
    print l[POS + 2], l[POS + 1], l[POS]
else:
    print -1

