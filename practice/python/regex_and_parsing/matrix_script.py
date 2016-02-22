#!/usr/bin/env python

import re

n, m = map(int, raw_input().strip().split())

a = ['' for _ in range(n * m)]

for ROW in range(n):
    r = raw_input().strip()
    for COL in range(m):
        a[COL * n + ROW] = r[COL]
s = ''.join(a)
print re.sub(r'(?<=[a-zA-Z0-9])([!@#$%&\s]+)(?=[a-zA-Z0-9])', ' ', s)

