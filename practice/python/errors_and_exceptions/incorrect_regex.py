#!/usr/bin/env python

import re

n = int(raw_input().strip())
for _ in range(n):
    s = raw_input().strip()
    try:
        re.compile(s)
        print True
    except:
        print False

