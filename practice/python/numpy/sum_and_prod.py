#!/usr/bin/env python

import numpy

n, m = map(int, raw_input().split())

a = []
for _ in range(n):
    a.append(map(int, raw_input().split()))
na = numpy.array(a)

s = numpy.sum(na, axis=0)
print numpy.product(s)

