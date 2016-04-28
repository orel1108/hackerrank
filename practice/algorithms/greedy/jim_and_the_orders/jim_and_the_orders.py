#!/usr/bin/env python

n = int(raw_input().strip())
t = []
for CNT in range(n):
    ti, di = map(int, raw_input().strip().split())
    t.append((ti + di, CNT + 1))
    
for VAL in sorted(t):
    print VAL[1],

