#!/usr/bin/env python

n = int(raw_input().strip())
k = 0
while n > 0:
    if n % 2 == 0:
        k += 1
    n //= 2
print pow(2, k)

