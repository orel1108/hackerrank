#!/usr/bin/env python

def log2(i_n):
    res = 0
    while i_n > 0:
        res += 1
        i_n //= 2
    return res - 1

t = int(raw_input().strip())
for _ in xrange(t):
    n = int(raw_input().strip())
    l = log2(n)
    
    rem1 = 1 if n % 2 == 0 else 5
    rem2 = 2 if l == 0 else 6 * l % 10
    print rem1 * rem2 % 10

