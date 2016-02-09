#!/usr/bin/env python

n = int(raw_input().strip())
t = tuple(map(int, raw_input().split()))

print hash(t)
