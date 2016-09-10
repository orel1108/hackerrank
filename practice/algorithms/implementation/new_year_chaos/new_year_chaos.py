#!/usr/bin/env python

def count_less_then(i_q, i_n):
    cnt = 0
    for POS in xrange(i_n - 1, -1, -1):
        if i_q[POS] - POS - 1 > 2:
            return -1
        for OPOS in xrange(max(0, i_q[POS] - 2), POS):
            if i_q[POS] < i_q[OPOS]:
                cnt += 1
    return cnt

t = int(raw_input().strip())
for _ in xrange(t):
    n = int(raw_input().strip())
    q = map(int, raw_input().strip().split())
    cnt = count_less_then(q, n)
    if cnt >= 0:
        print cnt
    else:
        print "Too chaotic"

