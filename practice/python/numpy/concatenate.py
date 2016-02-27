#!/usr/bin/env python

import numpy

n, m, p = map(int, raw_input().strip().split())

a = []
for _ in range(n):
    a.append(map(int, raw_input().strip().split()))
na = numpy.array(a)

b = []
for _ in range(m):
    b.append(map(int, raw_input().strip().split()))
nb = numpy.array(b)

print numpy.concatenate((na, nb))

