#!/usr/bin/env python

from fractions import gcd

n, k = map(int, raw_input().strip().split())
a = map(int, raw_input().strip().split())
g = reduce(gcd, a, a[0])
ans = 0
x = 2
while x * x < g + 1:
    if g % x == 0:
        ans = max(ans, k - k % x)
        ans = max(ans, k - k % (g // x))
    x += 1
ans = max(ans, k - k % g)
print ans

