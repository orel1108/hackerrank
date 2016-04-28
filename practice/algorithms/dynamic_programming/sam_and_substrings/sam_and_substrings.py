#!/usr/bin/env python

MOD = 10 ** 9 + 7

v = raw_input().strip()
n = len(v)
m = map(int, v)
s = 0
p = 10
for POS in range(n):
    s += (n - POS) * (p - 1) * m[n - POS - 1]
    p *= 10
    p %= MOD
    s %= MOD
print s * pow(9, MOD - 2, MOD) % MOD

