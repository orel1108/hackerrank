#!/usr/bin/env python

def solve(i_matrix, i_n):
    c = 0
    while c < i_n:
        for r in range(1, i_n):
            if m[r][c] < m[r - 1][c]:
                return False
        c += 1
    return True

t = int(raw_input().strip())
for _ in range(t):
    n = int(raw_input().strip())
    m = []
    for __ in range(n):
        m.append(sorted(raw_input()))
    a = solve(m, n)
    if not a:
        print 'NO'
    else:
        print 'YES'

