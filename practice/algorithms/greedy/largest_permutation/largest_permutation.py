#!/usr/bin/env python

n, k = map(int, raw_input().strip().split())
p = [0] + map(int, raw_input().strip().split())
d = [0 for _ in range(n + 1)]
for CNT in range(n + 1):
    d[p[CNT]] = CNT

cnt = 1
while cnt < n and k > 0:
    if p[cnt] != n - cnt + 1:
        pos = d[n - cnt + 1]
        d[p[cnt]] = d[n - cnt + 1]
        d[n - cnt + 1] = cnt
        p[cnt], p[pos] = p[pos], p[cnt]
        k -= 1
    cnt += 1
    
for CNT in range(1, n + 1):
    print p[CNT],

