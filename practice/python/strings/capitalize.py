#!/usr/bin/env python

s = raw_input().strip()
start = True
r = ''
for C in s:
    if start and not C.isspace():
        r += C.upper()
        start = False
    else:
        r += C
        if C.isspace():
            start = True
print r

