#!/usr/bin/env python

def to_int(i_chr):
    return 1 if i_chr.isupper() else 0

s = raw_input().strip()
m = map(to_int, s)
print sum(m) + 1

