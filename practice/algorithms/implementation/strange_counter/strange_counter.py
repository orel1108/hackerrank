#!/usr/bin/env python

t = int(raw_input().strip())
next_time = 3
add_time = 3
while next_time < t:
    add_time *= 2
    next_time += add_time
print next_time - t + 1

