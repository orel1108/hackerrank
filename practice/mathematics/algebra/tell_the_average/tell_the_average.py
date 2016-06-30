#!/usr/bin/env python

n = int(raw_input().strip())
a = map(lambda x: int(x) + 1, raw_input().strip().split())
print reduce(lambda x, y: x * y % 1000000007, a, 1) - 1

