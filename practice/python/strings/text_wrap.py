#!/usr/bin/env python

import textwrap

s = raw_input().strip()
n = int(raw_input().strip())
print textwrap.fill(s, n)

