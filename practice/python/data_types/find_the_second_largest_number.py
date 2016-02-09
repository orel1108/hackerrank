#!/usr/bin/env python

x = int(raw_input().strip())
values = map(int, raw_input().strip().split())

m = max(values)
n = min(values)
for i in range(x):
    if values[i] == m:
        values[i] = n - 1
print max(values)
