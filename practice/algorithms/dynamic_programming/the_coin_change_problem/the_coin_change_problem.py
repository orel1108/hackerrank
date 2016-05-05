#!/usr/bin/env python

def change(i_n, i_coins):
    ways = [0 for _ in range(i_n + 1)]
    ways[0] = 1
    for COIN in i_coins:
        for CNT in range(COIN, i_n + 1):
            ways[CNT] += ways[CNT - COIN]
    return ways[-1]

n, m = map(int, raw_input().strip().split())
coins = map(int, raw_input().strip().split())
print change(n, coins)

