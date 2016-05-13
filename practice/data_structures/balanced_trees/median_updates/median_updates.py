#!/usr/bin/env python

from __future__ import division
import bisect

def median(i_a, i_x):
    r = []
    n = len(i_a)
    for POS in xrange(n):
        if i_a[POS] == 'a':
            bisect.insort_right(r, i_x[POS])
            l = len(r)
            if l % 2 == 1:
                print r[l // 2]
            else:
                v = r[l // 2 - 1] + r[l // 2]
                print v // 2 if v % 2 == 0 else v / 2
        else:
            if i_x[POS] not in r:
                print 'Wrong!'
            else:
                r.remove(i_x[POS])
                l = len(r)
                if l % 2 == 1:
                    print r[l // 2]
                elif r:
                    v = r[l // 2 - 1] + r[l // 2]
                    print v // 2 if v % 2 == 0 else v / 2
                else:
                    print 'Wrong!'

n = int(raw_input().strip())
s = []
x = []
for _ in xrange(n):
    tmp = raw_input().strip().split(' ')
    s.append(tmp[0])
    x.append(int(tmp[1]))

median(s, x)

