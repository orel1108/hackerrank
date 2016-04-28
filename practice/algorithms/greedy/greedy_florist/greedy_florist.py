#!/usr/bin/env python

n, k = map(int, raw_input().strip().split())
c = sorted(map(int, raw_input().strip().split()), reverse=True)

res = 0
if n <= k:
    res = sum(c)
else:
    cnt = 1
    j = 0
    while j < n:
        res += cnt * sum(c[j:j + k])
        j += k
        cnt += 1
print res

