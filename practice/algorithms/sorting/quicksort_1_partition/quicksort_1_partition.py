#!/usr/bin/env python

def partition(ar):
    p = ar[0]
    smaller = filter(lambda x : x < p, ar)
    equal   = filter(lambda x : x == p, ar)
    greater = filter(lambda x : x > p, ar)
    total = smaller + equal + greater
    for VAL in total:
        print VAL,
    return ""

m = input()
ar = [int(i) for i in raw_input().strip().split()]
partition(ar)

