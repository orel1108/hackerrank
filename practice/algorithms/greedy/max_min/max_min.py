#!/usr/bin/env python

n = int(raw_input().strip())
k = int(raw_input().strip())
buff = [int(raw_input().strip()) for _ in range(0, n)]
buff.sort()

res = buff[k - 1] - buff[0]
for POS in range(1, n - k + 1):
    diff = buff[POS + k - 1] - buff[POS]
    if diff < res:
        res = diff
print res

