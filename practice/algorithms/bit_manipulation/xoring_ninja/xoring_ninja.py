#!/usr/bin/env python

t = int(raw_input().strip())
for _ in range(t):
    n = int(raw_input().strip())
    a = map(int, raw_input().strip().split())

    s = 0
    for VAL in a:
        s |= VAL
    s *= 2 ** (n - 1)
    print s % 1000000007

