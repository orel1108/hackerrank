#!/bin/python
from __future__ import division

def solve_1(arr):
    res = [0, 0, 0]
    for VAL in arr:
        if VAL > 0:
            res[0] += 1
        elif VAL < 0:
            res[1] += 1
        else:
            res[2] += 1
    return res

def solve_2(arr):
    res = [0, 0, 0]
    res[0] = len([VAL for VAL in arr if VAL > 0])
    res[1] = len([VAL for VAL in arr if VAL < 0])
    res[2] = len([VAL for VAL in arr if VAL == 0])
    return res

n = int(raw_input().strip())
arr = map(int, raw_input().strip().split(' '))

ans = solve_2(arr)
print ans[0] / n
print ans[1] / n
print ans[2] / n

