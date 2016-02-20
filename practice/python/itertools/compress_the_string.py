#!/usr/bin/env python

from itertools import groupby

s = raw_input().strip()
for K, G in groupby(s):
    print (len(list(G)), int(K)),

