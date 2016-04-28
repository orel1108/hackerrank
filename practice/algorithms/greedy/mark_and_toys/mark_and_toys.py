#!/usr/bin/env python

n, k = map(int, raw_input().strip().split())
prices = map(int, raw_input().strip().split())
prices.sort()

s = 0
c = 0
while s <= k:
    s += prices[c]
    c += 1
print c - 1

