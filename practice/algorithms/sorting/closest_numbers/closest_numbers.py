#!/usr/bin/env python

N = int(raw_input()) 
s = sorted(map(int, raw_input().split()))

curr_min = abs(s[0] - s[1])
for i in range(1, N - 1):
    if abs(s[i] - s[i + 1]) < curr_min:
        curr_min = abs(s[i] - s[i + 1])

pairs = set()
for i in range(N - 1):
    if abs(s[i] - s[i + 1]) == curr_min:
        pairs.add(tuple(sorted([s[i], s[i + 1]])))

for PAIR in sorted(pairs):
    print PAIR[0], PAIR[1],

