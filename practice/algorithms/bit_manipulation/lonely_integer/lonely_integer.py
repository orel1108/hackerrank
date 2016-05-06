#!/usr/bin/env python

def lonely_integer(i_arr):
    return reduce(lambda x, y: x ^ y, i_arr, 0)

n = int(raw_input().strip())
arr = map(int ,raw_input().strip().split())
print lonely_integer(arr)

