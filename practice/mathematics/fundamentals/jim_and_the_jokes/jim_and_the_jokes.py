#!/usr/bin/env python

def dec_rep(i_m, i_d):
    digits = map(int, list(i_d))
    base = int(i_m)
    
    if max(digits) >= base:
        return None
    
    res = digits[0]
    if len(digits) == 2:
        res = base * res + digits[1]
    return res
    
n = int(raw_input().strip())
dates = [0] * 366
for _ in xrange(n):
    m, d = raw_input().strip().split()
    pos = dec_rep(m, d)
    if pos:
        dates[pos] += 1

num_pairs = sum([val * (val - 1) / 2 for val in dates])
print num_pairs

