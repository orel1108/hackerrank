#!/usr/bin/env python

def max_prof(i_prices):
    res_prof = 0
    if not i_prices:
        return 0
    max_pos = i_prices.index(max(i_prices))
    if max_pos > 0 :
        for i in range(max_pos):
            res_prof -= i_prices[i]
        res_prof += (max_pos * i_prices[max_pos])
    res_prof += max_prof(i_prices[max_pos + 1:])
    
    return res_prof

t = int(raw_input().strip())
for _ in range(t) :
    n = int(raw_input().strip())
    prices = map(int, raw_input().strip().split())
    print max_prof(prices)

