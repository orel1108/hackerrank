#!/usr/bin/env python

import numpy

n = int(raw_input())
a = []
for _ in range(n):
    a.append(map(int, raw_input().split()))
na = numpy.array(a)

b = []
for _ in range(n):
    b.append(map(int, raw_input().split()))
nb = numpy.array(b)

print numpy.dot(na, nb)

