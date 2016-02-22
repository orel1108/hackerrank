#!/usr/bin/env python

import string

def to_ord(i_chr):
    s = string.lowercase + string.uppercase + '13579' + '02468'
    return s.index(i_chr)
    
s = raw_input().strip()
print reduce(lambda x, y: x+y, sorted(s, key=lambda c: to_ord(c)))

