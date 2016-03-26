#!/usr/bin/env python

n, k, q = map(int, raw_input().strip().split())
arr = map(int, raw_input().strip().split())

for _ in range(q):
    x = int(raw_input().strip())
    print arr[(x + n - k) % n]

