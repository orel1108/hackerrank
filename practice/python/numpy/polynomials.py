#!/usr/bin/env python

import numpy

c = map(float, raw_input().split())
v = float(raw_input())

print numpy.polyval(c, v)

