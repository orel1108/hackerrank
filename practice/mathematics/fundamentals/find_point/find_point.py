#!/usr/bin/env python

t = int(raw_input().strip())
for _ in xrange(t):
    px, py, qx, qy = map(int, raw_input().strip().split())
    print 2 * qx - px, 2 * qy - py

