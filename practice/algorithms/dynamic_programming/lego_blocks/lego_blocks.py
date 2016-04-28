#!/usr/bin/env python

MAX_N = 1000

decomp_n = [0, 1, 2, 4, 8]
for CNT in range(1, MAX_N):
    v = decomp_n[CNT] + decomp_n[CNT + 1] + decomp_n[CNT + 2] + decomp_n[CNT + 3]
    v %= 1000000007
    decomp_n.append(v)

t = int(raw_input().strip())
for _ in range(t):
    n, m = map(int, raw_input().strip().split())
    p = []
    for M in range(m + 1):
        p.append(pow(decomp_n[M], n, 1000000007))
    r = [0 for _ in range(m + 1)]
    r[1] = 1
    for POS in range(2, m + 1):
        r[POS] = p[POS]
        for IPOS in range(1, POS):
            r[POS] = (r[POS] - r[IPOS] * p[POS - IPOS]) % 1000000007
    print r[-1]

