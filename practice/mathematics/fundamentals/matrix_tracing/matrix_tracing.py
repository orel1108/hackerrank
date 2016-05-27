#!/usr/bin/env python

def fact_mod(i_n, i_mod):
    f = 1
    for N in xrange(2, i_n + 1):
        f *= N
        if f >= i_mod:
            f %= i_mod
    return f

def binom_coeff(i_m, i_n, i_mod):
    num = fact_mod(i_m + i_n - 2, i_mod)
    den = fact_mod(i_n - 1, i_mod) * fact_mod(i_m - 1, i_mod)
    
    return num * pow(den, i_mod - 2, i_mod) % i_mod

t = int(raw_input().strip())
for _ in xrange(t):
    m, n = map(int, raw_input().strip().split())
    print binom_coeff(m, n, 1000000007)

