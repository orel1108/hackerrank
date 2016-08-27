#!/usr/bin/env python

def solve(i_c, i_n, i_pos):
    if i_pos < i_n - 1:
        if i_pos < i_n - 2 and i_c[i_pos + 2] == 0:
            return 1 + solve(i_c, i_n, i_pos + 2)
        else:
            return 1 + solve(i_c, i_n, i_pos + 1)
    return 0

n = int(raw_input().strip())
c = map(int, raw_input().strip().split())
print solve(c, n, 0)

