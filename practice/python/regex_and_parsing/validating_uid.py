#!/usr/bin/env python

import re

n = int(raw_input().strip())
for _ in range(n):
    s = raw_input().strip()
    r1 = r'[A-Za-z0-9]{10}'
    r2 = r'([A-Z].*){2}'
    r3 = r'([0-9].*){3}'
    r4 = r'(.).*\1'
    if re.search(r1, s) and re.search(r2, s) and re.search(r3, s) and (not re.search(r4, s)):
        print 'Valid'
    else:
        print 'Invalid'

