#!/usr/bin/env python

import bisect

PRIMES = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
PRODS = [1]
for P in PRIMES:
    PRODS.append(PRODS[-1] * P)
    if PRODS[-1] > 10 ** 18:
        break

n = int(raw_input().strip())
for _ in xrange(n):
    x = int(raw_input().strip())
    pos = bisect.bisect(PRODS, x)
    print pos - 1

