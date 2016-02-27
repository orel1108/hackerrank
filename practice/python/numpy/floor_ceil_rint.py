#!/usr/bin/env python

import numpy

na = numpy.array(map(float, raw_input().split()))
print numpy.floor(na)
print numpy.ceil(na)
print numpy.rint(na)

