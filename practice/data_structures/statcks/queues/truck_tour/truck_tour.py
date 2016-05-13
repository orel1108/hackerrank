#!/usr/bin/env python

n = int(raw_input().strip())
pd = []
for _ in xrange(n):
    pd.append(map(int, raw_input().strip().split()))

pos = 0
while pos < n:
    tp = 0
    td = 0
    cnt = 0
    while cnt < n and tp >= td:
        tp += pd[(pos + cnt) % n][0]
        td += pd[(pos + cnt) % n][1]
        cnt += 1
    if cnt == n:
        break
    pos += cnt
print pos

