#!/usr/bin/env python

n = int(raw_input().strip())
arr = map(int, raw_input().strip().split())

s  = sum(arr)
s1 = sum([(POS + 1) * arr[POS] for POS in xrange(n)])

part_sum = arr[0]
res = s1
for K in xrange(2, n + 1):
    sk = s1 - (K - 1) * s + n * part_sum
    part_sum += arr[K - 1]
    if sk > res:
        res = sk
print res

