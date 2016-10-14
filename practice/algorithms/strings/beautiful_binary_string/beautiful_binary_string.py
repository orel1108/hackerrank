#!/usr/bin/env python

n = int(raw_input().strip())
b = list(raw_input().strip())

cnt = 0
if len(b) >= 0:
    for POS in xrange(len(b) - 2):
        if ''.join(b[POS:POS + 3]) == "010":
            b[POS + 2] = '1'
            cnt += 1
print cnt

