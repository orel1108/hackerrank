#!/usr/bin/env python

def solve(i_p):
    stack = []
    max_days_alive = 0
    for VAL in i_p:
        days_alive = 0
        while stack and VAL <= stack[-1][0]:
            days_alive = max(days_alive, stack[-1][1])
            stack.pop()
        days_alive = 0 if not stack else days_alive + 1
        max_days_alive = max(max_days_alive, days_alive)
        stack.append([VAL, days_alive])
    return max_days_alive

n = int(raw_input().strip())
p = map(int, raw_input().strip().split())

r = solve(p)
print r

