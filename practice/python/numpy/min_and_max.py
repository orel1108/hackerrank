#!/usr/bin/env python

import numpy

n, m = map(int, raw_input().split())
a = []
for _ in range(n):
    a.append(map(int, raw_input().split()))
na = numpy.array(a)

r = numpy.min(na, axis=1)
print numpy.max(r)

