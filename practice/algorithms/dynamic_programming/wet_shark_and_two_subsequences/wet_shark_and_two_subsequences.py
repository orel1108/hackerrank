#!/usr/bin/env python

MOD = 10 ** 9 + 7

m, r, s = map(int, raw_input().strip().split())
a = map(int, raw_input().strip().split())

L = (r + s) // 2
R = (r - s) // 2

res = 0

if R >= 0:
    dp = [[0 for _ in range(2001)] for __ in range(101)]

    dp[0][0] = 1
    for I in range(m - 1, -1, -1):
        for J in range(m, 0, -1):
            for S in range(2000, -1, -1):
                if S >= a[I]:
                    dp[J][S] += dp[J - 1][S - a[I]] % MOD

    for I in range(1, m + 1):
        res += dp[I][L] * dp[I][R] % MOD
print res % MOD

