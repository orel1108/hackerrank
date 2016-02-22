#!/usr/bin/env python

import re

t = int(raw_input().strip())
for _ in range(t):
    f = raw_input().strip()
    print bool(re.match(r"[+-]?(\d*)[.](\d+)$", f))

