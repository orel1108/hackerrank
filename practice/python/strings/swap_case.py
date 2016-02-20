#!/usr/bin/env python

s = raw_input().strip()
cs = ''
for c in s:
    if c.islower():
        cs += c.upper()
    elif c.isupper():
        cs += c.lower()
    else:
        cs += c
print cs

