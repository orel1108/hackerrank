#!/usr/bin/env python

import numpy

na = numpy.array(map(int, raw_input().split()))
nb = numpy.array(map(int, raw_input().split()))

print numpy.inner(na, nb)
print numpy.outer(na, nb)

