#!/usr/bin/env python

import numpy

dim = map(int, raw_input().split())
print numpy.zeros(tuple(dim), dtype = numpy.int)
print numpy.ones(tuple(dim), dtype = numpy.int)

