#!/usr/bin/env python

t = int(raw_input().strip())
for _ in xrange(t):
    n = int(raw_input().strip())
    a = map(int, raw_input().strip().split())
    cnt_1 = 0
    cnt_2 = 0
    for POS in xrange(n):
        if a[POS] == 1:
            cnt_1 += 1
        elif a[POS] == 2:
            cnt_2 += 1
    s = cnt_1 * (n - 1) + cnt_2 * (cnt_2 - 1) / 2
    print s

