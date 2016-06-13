#!/usr/bin/env python

def count(i_p, i_n):
    if i_n < i_p:
        return 0
    return i_n // i_p + count(i_p, i_n // i_p)

def bsearch(i_n):
    left = 0
    right = 5 * i_n
    while right - left > 1:
        mid = (left + right) // 2
        if count(5, mid) < i_n:
            left = mid
        else:
            right = mid
    return right

t = int(raw_input().strip())
for _ in xrange(t):
    n = int(raw_input().strip())
    print bsearch(n)

