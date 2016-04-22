#!/usr/bin/env python

def used_edges(i_n, i_k):
    g1 = i_n % i_k
    g2 = i_k - g1
    s1 = i_n / i_k + 1
    s2 = s1 - 1
    prod1 = g1 * s1
    prod2 = g2 * s2
    return ((prod1 + prod2) * (prod1 + prod2) - (prod1 * s1 + prod2 * s2)) / 2

t = int(raw_input().strip())
for _ in range(t):
    n, m = map(int, raw_input().strip().split())
    r = 2
    
    while (1.0 - 1.0 / r) * n * n / 2.0 < m:
        r += 1
    while used_edges(n, r) < m:
        r += 1
    print r

