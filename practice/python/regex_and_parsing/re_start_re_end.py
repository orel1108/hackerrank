#!/usr/bin/env python

import re

s = raw_input().strip()
k = raw_input().strip()

n = len(k) - 1
a = 0
while True:
    m = re.search(k, s)
    if not m:
        if a == 0:
            print (-1, -1)
        break
    start = m.start()
    print (start + a, start + n + a)
    s = ''.join(s[start + 1:])
    a += start + 1

