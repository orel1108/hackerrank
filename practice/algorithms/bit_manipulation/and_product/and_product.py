#!/usr/bin/env python

POWS = [1 << POS for POS in range(33)]

t = int(raw_input().strip())
for _ in xrange(t):
    a, b = map(int, raw_input().strip().split())
    c = b - a + 1
    if c == 1 or c == 2:
        print a & b
    else:
        pos = 0
        while c > POWS[pos]:
            pos += 1
        a //= POWS[pos]
        b //= POWS[pos]
        r = 2 ** 32 - 1
        while a <= b:
            r &= a
            a += 1
        print r * POWS[pos]

