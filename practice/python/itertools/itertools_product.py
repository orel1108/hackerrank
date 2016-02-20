#!/usr/bin/env python

from itertools import product

A = map(int, raw_input().strip().split())
B = map(int, raw_input().strip().split())
C = product(A, B)
for c in C:
    print c,

