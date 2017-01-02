#!/usr/bin/env python

a = map(int, raw_input().strip().split())
print sum(a) - max(a), sum(a) - min(a)

