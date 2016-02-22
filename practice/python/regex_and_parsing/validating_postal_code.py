#!/usr/bin/env python

import re

r1 = r'^[1-9]\d{5}$'
r2 = r'(\d)\d\1'

s = raw_input().strip()
print bool(re.search(r1, s)) and len(re.findall(r'(.)(?=.\1)',s)) < 2

