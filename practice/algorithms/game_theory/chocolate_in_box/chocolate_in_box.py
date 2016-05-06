#!/usr/bin/env python

n = int(raw_input().strip())
a = map(int, raw_input().strip().split())

x = reduce(lambda s, t: s ^ t, a)

if x == 0:
    print 0
else:
    cnt = 0
    for VAL in a:
        if x ^ VAL < VAL:
            cnt += 1
    print cnt

