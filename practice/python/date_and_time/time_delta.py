#!/usr/bin/env python

from dateutil.parser import parse

t = int(raw_input().strip())
for _ in range(t):
	start = parse(raw_input().strip())
	end   = parse(raw_input().strip())
	print abs(int((start - end).total_seconds()))

