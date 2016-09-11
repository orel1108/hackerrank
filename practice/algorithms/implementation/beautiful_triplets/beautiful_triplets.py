#!/usr/bin/env python

n, d = map(int, raw_input().strip().split())
arr = map(int, raw_input().strip().split())

res = 0
for POS1 in xrange(n):
    for POS2 in xrange(POS1 + 1, n):
        if arr[POS2] - arr[POS1] > d:
            break
        if arr[POS2] - arr[POS1] == d:
            for POS3 in xrange(POS2 + 1, n):
                if arr[POS3] - arr[POS2] > d:
                    break
                if arr[POS3] - arr[POS2] == d:
                    res += 1
print res

