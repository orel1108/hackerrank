#!/usr/bin/env python

n, m = map(int, raw_input().strip().split())
s = []
for _ in range(n):
    row = map(int, raw_input().strip().split())
    s.append(row)

k = int(raw_input().strip())
for ROW in sorted(s, key=lambda x:x[k]):
    for VAL in ROW:
        print VAL,
    print

