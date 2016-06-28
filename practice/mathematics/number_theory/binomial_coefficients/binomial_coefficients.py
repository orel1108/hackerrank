#!/usr/bin/env python

def decompose(i_value, i_prime):
    coeffs = []
    while i_value > 0:
        coeffs.append(i_value % i_prime)
        i_value //= i_prime
    return coeffs

t = int(raw_input().strip())
for _ in range(t):
    n, p = map(int, raw_input().strip().split())
    coeffs = decompose(n, p)
    r = reduce(lambda x, y: x * (y + 1), coeffs, 1)
    print n + 1 - r

