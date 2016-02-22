#!/usr/bin/env python

def normalize(val):
    res = 0
    for i in range(10):
        res +=  ((val % 10) * (10 ** i))
        val //= 10
    return res

n = int(raw_input().strip())

tell_nums = []
for _ in range(n):
    tn = int(raw_input().strip())
    tell_nums.append(normalize(tn))
    
sl = sorted(tell_nums)
for i in range(len(tell_nums)):
    print "+91", sl[i] // 100000, sl[i] % 100000

