#!/usr/bin/env python

t = int(raw_input().strip())
for _ in range(t):
    n, k = map(int, raw_input().strip().split())
    w = map(int, raw_input().strip().split())
    
    b = set()
    for ITEM in w:
        if ITEM <= k:
            b.add(ITEM)

    dp = [0 for __ in range(k + 1)]
    for POS in range(1, k + 1):
        for VAL in b:
            if VAL <= POS:
                dp[POS] = max(dp[POS], VAL + dp[POS - VAL])
    print dp[k]

