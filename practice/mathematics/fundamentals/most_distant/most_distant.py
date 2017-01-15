#!/usr/bin/env python

import math

n = int(raw_input().strip())

x = []
y = []
for _ in range(n):
    a, b = map(float, raw_input().split())
    if a == 0:
        y.append((a, b))
    else:
        x.append((a, b))
        
x = sorted(x)
y = sorted(y)

def dist(p0, p1):
    return math.sqrt(pow(p0[0] - p1[0], 2) + pow(p0[1] - p1[1], 2))

cand = [x[0], x[-1], y[0], y[-1]]

r = 0
for i in range(4):
    for j in range(4):
        d = dist(cand[i], cand[j])
        if d > r:
            r = d
print "%.6f" % r

