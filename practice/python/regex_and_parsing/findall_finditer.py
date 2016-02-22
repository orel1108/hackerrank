#!/usr/bin/env python

import re

s = raw_input().strip()
f = re.findall(r'[qwrtypsdfghjklzxcvbnmQWRTYPSDFGHJKLZXCVBNM]([aeiouAEIOU]{2,})(?=[qwrtypsdfghjklzxcvbnmQWRTYPSDFGHJKLZXCVBNM])', s)

if f:
    for SUB in f:
        if SUB:
            print SUB
else:
    print -1

