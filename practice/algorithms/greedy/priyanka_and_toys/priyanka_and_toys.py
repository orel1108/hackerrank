#!/usr/bin/env python

n = int(raw_input().strip())
w = map(int, raw_input().strip().split())
w.sort()

cnt = 0
res = 0

while cnt < n:
    in_cnt = 0
    res += 1
    while cnt + in_cnt < n and w[cnt + in_cnt] - w[cnt] <= 4:
        in_cnt += 1
    cnt += in_cnt
print res

