#!/usr/bin/env python

from __future__ import division

n = input()
s = set(map(int, raw_input().strip().split()))
print sum(s) / len(s)

