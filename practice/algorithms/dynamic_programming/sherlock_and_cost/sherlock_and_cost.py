#!/usr/bin/env python

t = int(raw_input().strip())
for _ in range(t):
    n = int(raw_input().strip())
    b = map(int, raw_input().strip().split())
    s1 = 0
    s2 = 0
    b1 = [0 for _ in range(n)]
    b2 = [0 for _ in range(n)]
    for pos in range(1, n):
        s1 = max(abs(1 - b[pos - 1]) + b2[pos - 1], b1[pos - 1])
        s2 = max(abs(b[pos] - 1) + b1[pos - 1], abs(b[pos] - b[pos - 1]) + b2[pos - 1])
        b1[pos] = s1
        b2[pos] = s2
    print max(s1, s2)

