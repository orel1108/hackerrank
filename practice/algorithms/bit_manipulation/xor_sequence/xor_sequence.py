#!/usr/bin/env python

def xor_range(i_n):
    r = (i_n % 8) // 2
    if r == 0:
        return i_n
    elif r == 1:
        return 2
    elif r == 2:
        return i_n + 2
    else:
        return 0

q = int(raw_input().strip())
for _ in xrange(q):
    l, r = map(int, raw_input().strip().split())
    print xor_range(r) ^ xor_range(l - 1)

