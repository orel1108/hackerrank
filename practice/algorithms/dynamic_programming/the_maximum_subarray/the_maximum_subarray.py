#!/usr/bin/env python

def cadane(i_a):
    curr_max = res_max = i_a[0]
    for VAL in i_a[1:]:
        curr_max = max(VAL, curr_max + VAL)
        res_max = max(res_max, curr_max)
    return res_max

t = int(raw_input().strip())
for _ in range(t):
    n = int(raw_input().strip())
    a = map(int, raw_input().strip().split())
    max_elem = max(a)
    res = sum([item for item in a if item >= 0])
    if max_elem <= 0:
        res = max_elem
    print cadane(a), res

