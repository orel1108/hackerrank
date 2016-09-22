#!/usr/bin/env python

def process(i_list):
    included = set()
    res = []
    for CHR in i_list:
        if CHR not in included:
            included.add(CHR)
            res.append(CHR)
    return ''.join(res)

s = raw_input().strip()
k = int(raw_input().strip())

for PART_NUM in xrange(len(s) // k):
    print process(s[PART_NUM * k : (PART_NUM + 1) * k])

