#!/usr/bin/env python

import bisect

def insert_pos(i_a, i_val):
    lo = 0
    hi = len(i_a) - 1
    mid = 0
    while lo <= hi:
        mid = (lo + hi) // 2
        if i_a[mid] < i_val:
            lo = mid + 1
        elif i_a[mid] > i_val:
            hi = mid - 1
        else:
            return False, mid
    return True, lo

t = int(raw_input())
for _ in range(t):
    n, m = map(int, raw_input().split())
    a = map(int, raw_input().split())
    part = [a[0] % m]
    for CNT in range(1, n):
        part.append((part[-1] + a[CNT]) % m)

    diffs = []
    s = []
    for CNT in range(n):
        pos = bisect.bisect_left(s, part[CNT])
        if pos < len(s):
            v = part[CNT] - s[pos]
            if v < 0:
                diffs.append(v)
        p = insert_pos(s, part[CNT])
        if p[0]:
            s.insert(p[1], part[CNT])
    print max(max(part), m + max(diffs))

