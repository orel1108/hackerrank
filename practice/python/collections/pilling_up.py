#!/usr/bin/env python

t = int(raw_input().strip())
for _ in range(t):
    n = int(raw_input().strip())
    a = map(int, raw_input().strip().split())
    r = []
    left = 0
    right = n - 1
    while left <= right:
        if a[left] >= a[right]:
            r.append(a[left])
            left += 1
        else:
            r.append(a[right])
            right -= 1
    print "Yes" if all(earlier >= later for earlier, later in zip(r, r[1:])) else "No"

