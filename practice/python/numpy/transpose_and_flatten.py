#!/usr/bin/env python

import numpy

n, m = map(int, raw_input().strip().split())

a = []
for _ in range(n):
    a.append(map(int, raw_input().strip().split()))
    
na = numpy.array(a)

print numpy.transpose(na)
print na.flatten()

