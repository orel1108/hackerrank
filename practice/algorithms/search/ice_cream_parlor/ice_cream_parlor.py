#!/usr/bin/env python

t = int(raw_input().strip())
for _ in range(t):
    m = int(raw_input().strip())
    n = int(raw_input().strip())
    a = map(int, raw_input().strip().split())
    
    for POS in range(n - 1):
        for IPOS in range(POS + 1, n):
            if a[POS] + a[IPOS] == m:
                print POS + 1, IPOS + 1

