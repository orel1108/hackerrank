#!/usr/bin/env python

from math import factorial

MOD = 1000000007

CVAL = {}
CKEY = set()

WAYS = {}
KEYS = set()

def num_ways_1d_util(i_pos, i_d, i_m):
    if (i_pos, i_d, i_m) in KEYS:
        return WAYS[(i_pos, i_d, i_m)]
    
    if i_pos < 1 or i_pos > i_d:
        return 0
    if i_m == 0:
        return 1
    
    res = num_ways_1d_util(i_pos - 1, i_d, i_m - 1) + num_ways_1d_util(i_pos + 1, i_d, i_m - 1)
    
    WAYS[(i_pos, i_d, i_m)] = res % MOD
    KEYS.add((i_pos, i_d, i_m))
    
    return WAYS[(i_pos, i_d, i_m)]

def num_ways_1d(i_pos, i_d, i_m):
    res = {}
    for M in range(i_m + 1):
        res[M] = num_ways_1d_util(i_pos, i_d, M) % MOD
    return res

def num_ways_1d_ind(i_x, i_d, i_m, i_n):
    res = []
    for POS in range(i_n):
        nw = num_ways_1d(i_x[POS], i_d[POS], i_m)
        res.append(dict(nw))
    return res

def cnk(i_n, i_k):
    global CVAL, CKEY
    if (i_n, i_k) in CKEY:
        return CVAL[(i_n, i_k)]
    num = factorial(i_n)
    den = factorial(i_n - i_k) * factorial(i_k)
    res = num // den
    CVAL[(i_n, i_k)] = res % MOD
    CKEY.add((i_n, i_k))
    
    return res % MOD

def solve(i_x, i_d, i_m, i_n):
    ind = num_ways_1d_ind(i_x, i_d, i_m, i_n)
    f = [[0 for _ in range(i_m + 1)] for __ in range(i_n)]
    for M in range(i_m + 1):
        f[0][M] = ind[0][M]
    for J in range(1, i_n):
        for K in range(i_m + 1):
            for I in range(K + 1):
                f[J][K] += cnk(K, I) * f[J - 1][I] * ind[J][K - I]
            f[J][K] %= MOD
    return f[i_n - 1][i_m] % MOD

t = int(raw_input().strip())
for _ in range(t):
    n, m = map(int, raw_input().strip().split())
    x = map(int, raw_input().strip().split())
    d = map(int, raw_input().strip().split())
    print solve(x, d, m, n)

