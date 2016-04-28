#!/usr/bin/env python

t = int(raw_input().strip())
for _ in range(t):
    n = int(raw_input().strip())
    a = map(int, raw_input().strip().split())
    m = min(a)
    ans = 10 ** 10
    for N in [m, m - 1, m - 2, m - 5]:
        cnt = 0
        for VAL in a:
            c = VAL - N
            cnt += c // 5 + (c % 5) // 2 + (c % 5) % 2
        if cnt < ans:
            ans = cnt
    print ans

