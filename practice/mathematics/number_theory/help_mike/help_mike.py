#!/usr/bin/env python

def count(i_n, i_k):
    K = 0
    vals = []
    while K < i_k:
        vals.append((i_n + K) // i_k)
        K += 1
    d = i_n // i_k
    r = i_n % i_k
    if r > 0:
        r -= 1
    res = sum(vals) * (i_n // i_k) + sum(vals[:r])
    if i_k % 2 == 0:
        res -= d
    if i_n % i_k == 0:
        res -= d
    if r > i_k // 2:
        res += 2
    return res // 2

t = int(raw_input().strip())
for _ in xrange(t):
    n, k = map(int, raw_input().strip().split())
    print count(n, k)

