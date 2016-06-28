#!/usr/bin/env python

from math import log10

def num_digits(i_value):
    if i_value == 0:
        return 1
    return int(log10(i_value)) + 1

STRANGE_VALS = set(range(10))
curr = range(1, 10)
while curr and min(curr) < 10 ** 18:
    new_curr = set([])
    for VAL in curr:
        n = num_digits(VAL)
        d = VAL * n
        if d != VAL and num_digits(d) == n:
            new_curr.add(d)
        d = VAL * (n + 1)
        if num_digits(d) == n + 1:
            new_curr.add(d)
        d = VAL * (n + 2)
        if num_digits(d) == n + 2:
            new_curr.add(d)
    curr = [VAL for VAL in new_curr]
    for VAL in curr:
        STRANGE_VALS.add(VAL)
STRANGE_VALS = sorted(STRANGE_VALS)

t = int(raw_input().strip())
for _ in range(t):
    L, R = map(int, raw_input().strip().split())
    l = 0
    while l < len(STRANGE_VALS) and L > STRANGE_VALS[l]:
        l += 1
    r = 0
    while r < len(STRANGE_VALS) and R >= STRANGE_VALS[r]:
        r += 1
    print r - l

