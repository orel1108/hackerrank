#!/usr/bin/env python

def solve(i_a, i_n):
    b = sorted(i_a)
    idx = {}
    for POS in xrange(i_n):
        idx[i_a[POS]] = POS
    r = 0
    for POS in xrange(i_n):
        if i_a[POS] != b[POS]:
            r += 1
            p = idx[b[POS]]
            i_a[POS], i_a[p] = i_a[p], i_a[POS]
            idx[i_a[POS]] = POS
            idx[i_a[p]] = p
    return r

n = int(raw_input().strip())
a = map(int, raw_input().strip().split())
c = list(reversed(a))
print min(solve(a, n), solve(c, n))

