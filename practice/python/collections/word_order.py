#!/usr/bin/env python

from collections import OrderedDict, Counter

s = []

n = int(raw_input().strip())
for _ in range(n):
    w = raw_input().strip()
    s.append(w)

d = OrderedDict((W, True) for W in s)
cnt = Counter(s)

print len(cnt)

for VAL in d:
    print cnt[VAL],

