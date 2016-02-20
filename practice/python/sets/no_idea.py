#!/usr/bin/env python

from collections import defaultdict

freq = defaultdict(int)
n, m = map(int, raw_input().strip().split())

arr = map(int, raw_input().strip().split())
A = set(map(int, raw_input().strip().split()))
B = set(map(int, raw_input().strip().split()))

for VAL in arr:
    freq[VAL] += 1

C = set(arr)
CA = C.intersection(A)
CB = C.intersection(B)

happiness = 0
for VAL in CA:
    happiness += freq[VAL]
for VAL in CB:
    happiness -= freq[VAL]

print happiness

