#!/usr/bin/env python

MOD = 1000000000
MAX_N = 2000
pascal = [[1, 1]]
for _ in xrange(MAX_N):
    b = [1,]
    for CNT in xrange(len(pascal[-1]) - 1):
        d = pascal[-1][CNT] + pascal[-1][CNT + 1]
        d %= MOD
        b.append(d)
    b.append(1)
    pascal.append([VAL for VAL in b])
    
t = int(raw_input().strip())
for _ in xrange(t):
    n = int(raw_input().strip())
    k = int(raw_input().strip())
    print pascal[k + n - 2][n - 1]

