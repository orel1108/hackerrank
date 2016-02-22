#!/usr/bin/env python

import re

n = int(raw_input().strip())
r = r'(^[456]\d{15})$'
s = r'(^[456]\d{3})-(\d{4})-(\d{4})-(\d{4})$'
t = r'([0-9])(-|\1){4}'

for _ in range(n):
    c = raw_input().strip()
    if (re.search(r, c) or re.search(s, c)) and not re.search(t, c):
        print 'Valid'
    else:
        print 'Invalid'

