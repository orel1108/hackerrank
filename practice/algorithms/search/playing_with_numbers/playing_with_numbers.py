#!/usr/bin/env python

import bisect

n = int(raw_input().strip())
a = sorted(map(int, raw_input().strip().split()))
q = int(raw_input().strip())
v = map(int, raw_input().strip().split())

part_sums = [0]
for POS in range(n):
    part_sums.append(part_sums[-1] + a[POS])

x = 0
for Q in v:
    x += Q
    pos = bisect.bisect_right(a, -x)
    left = part_sums[pos] + x * pos
    right = (part_sums[-1] - part_sums[pos]) + x * (n - pos)
    print abs(left) + right

