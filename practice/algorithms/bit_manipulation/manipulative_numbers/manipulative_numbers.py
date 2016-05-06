#!/usr/bin/env python

n = int(raw_input().strip())
a = map(int, raw_input().strip().split())

k = -1
for BIT in range(31, -1, -1):
    d = {}
    for VAL in a:
        h = VAL >> BIT
        if h in d.keys():
            d[h] += 1
        else:
            d[h] = 1
            
    is_valid = True
    for KEY in d.keys():
        if d[KEY] > n // 2:
            is_valid = False
            break
    if is_valid:
        k = BIT
        break
print k

