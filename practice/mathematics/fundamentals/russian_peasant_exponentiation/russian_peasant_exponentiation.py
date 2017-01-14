#!/usr/bin/env python

def mult_complex_mod(i_a, i_b, i_mod):
    return [(i_a[0] * i_b[0] - i_a[1] * i_b[1]) % i_mod, (i_a[0] * i_b[1] + i_a[1] * i_b[0]) % i_mod]

def pow_complex_mod(i_a, i_deg, i_mod):
    res = [1, 0]
    while i_deg > 0:
        if i_deg % 2 == 1:
            res = mult_complex_mod(res, i_a, i_mod)
        i_a = mult_complex_mod(i_a, i_a, i_mod)
        i_deg //= 2
    return res

q = int(raw_input().strip())
for _ in xrange(q):
    a, b, k, m = map(int, raw_input().strip().split())
    r = pow_complex_mod([a, b], k, m)
    print r[0], r[1]

