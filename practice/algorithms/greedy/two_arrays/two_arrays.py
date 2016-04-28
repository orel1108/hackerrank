#!/usr/bin/env python

t = int(raw_input().strip())
for _ in range(t):
    n, k = map(int, raw_input().strip().split())
    a = map(int, raw_input().strip().split())
    b = map(int, raw_input().strip().split())
    a.sort()
    b.sort()
    
    ans = True
    for POS in range(n):
        if a[POS] + b[n - POS - 1] < k:
            ans = False
            break
    if ans:
        print "YES"
    else:
        print "NO"

