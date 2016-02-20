#!/usr/bin/env python

from collections import OrderedDict

d = OrderedDict()
n = int(raw_input().strip())

for _ in range(n):
    s = raw_input().strip().split()
    name = ' '.join(s[:-1])
    price = int(s[-1])
    if name in d.keys():
        d[name] += price
    else:
        d[name] = price

for KEY in d.keys():
    print KEY, d[KEY]

