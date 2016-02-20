#!/usr/bin/env python

from collections import Counter

k = input()

r = Counter(map(int, raw_input().strip().split()))
for KEY in r:
    if r[KEY] == 1:
        print KEY
        break

