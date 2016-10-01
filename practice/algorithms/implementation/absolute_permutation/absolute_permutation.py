#!/usr/bin/env python

t = int(raw_input().strip())
for _ in xrange(t):
    n, k = map(int, raw_input().strip().split())
    res = [0 for _ in xrange(n)]
    used = set()
    for POS in xrange(1, n + 1):
        if POS > k and (POS - k) not in used:
            res[POS - 1] = POS - k
            used.add(POS - k)
        else:
            res[POS - 1] = POS + k
            used.add(POS + k)
    if sorted(res) == range(1, n + 1):
        for VAL in res:
            print VAL,
        print
    else:
        print -1

