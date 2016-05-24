#!/usr/bin/env python

import math

L, s1, s2 = map(float, raw_input().strip().split())
q = int(raw_input().strip())
for _ in xrange(q):
    qi = int(raw_input().strip())
    print '%.6f' % (abs(math.sqrt(2.0 * qi) - math.sqrt(2.0) * L) / abs(s1 - s2))

