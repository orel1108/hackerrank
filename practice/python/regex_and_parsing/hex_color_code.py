#!/usr/bin/env python

import re

n = int(raw_input().strip())

r1 = re.compile(r'#[0-9a-fA-F]{6}|#[0-9a-fA-F]{3}')
r2 = re.compile(r'^(#[0-9a-fA-F]{6}|#[0-9a-fA-F]{3})')

colors = []
tags = []

for _ in range(n):
    line = raw_input().strip()
    c1 = r1.findall(line)
    c2 = r2.findall(line)
    if c1:
        for M in c1:
            colors.append(M)
    if c2:
        for M in c2:
            tags.append(M)

res = [COLOR for COLOR in colors if COLOR not in tags]
for C in res:
    print C

