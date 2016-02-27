#!/usr/bin/env python

import numpy

a = numpy.array(map(int, raw_input().strip().split()))
print numpy.reshape(a, (3, 3))

