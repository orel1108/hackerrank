#!/usr/bin/env python

import numpy

n = int(raw_input())

a = []
for _ in range(n):
    a.append(map(float, raw_input().split()))
na = numpy.array(a)

print numpy.linalg.det(na)

