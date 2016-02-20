#!/usr/bin/env python

from collections import Counter

X = int(raw_input().strip())
SIZE = Counter(map(int, raw_input().strip().split()))
N = int(raw_input().strip())
S = 0

for _ in range(N):
    s, price = map(int, raw_input().strip().split())
    if s in SIZE and SIZE[s] > 0:
        S += price
        SIZE[s] -= 1
print S

