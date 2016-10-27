#!/usr/bin/env python

n = int(raw_input().strip())

arr = [2]
for _ in xrange(n - 1):
    arr.append((arr[-1] * 3) // 2)
print sum(arr)

