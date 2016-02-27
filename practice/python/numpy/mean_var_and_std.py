#!/usr/bin/env python

import numpy

n, m = map(int, raw_input().split())
a = []
for _ in range(n):
    a.append(map(int, raw_input().split()))
na = numpy.array(a)

print numpy.mean(na, axis=1)
print numpy.var(na, axis=0)
print numpy.std(na)

