#!/usr/bin/env python

from collections import Counter

n = int(raw_input().strip())
a = map(int, raw_input().strip().split())
counter = Counter(a)

for VAL in range(100):
    if VAL in counter.keys():
        while counter[VAL] > 0:
            print VAL,
            counter[VAL] -= 1
