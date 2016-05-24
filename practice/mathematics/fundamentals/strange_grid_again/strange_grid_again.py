#!/usr/bin/env python

r, c = map(int, raw_input().strip().split())
r -= 1
c -= 1
t = 10 * (r // 2) + r % 2 + 2 * c
print t

