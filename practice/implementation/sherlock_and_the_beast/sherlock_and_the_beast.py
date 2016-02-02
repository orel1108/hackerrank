#!/bin/python

import sys

t = int(raw_input().strip())
for _ in range(t):
    n = int(raw_input().strip())
    k = 0
    while k <= n and (n - k) % 3 != 0:
        k += 5
    if k <= n:
        print '5' * (n - k) + '3' * k
    else:
        print -1
