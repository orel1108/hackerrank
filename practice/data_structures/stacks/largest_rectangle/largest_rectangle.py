#!/usr/bin/env python

def max_area(i_heights):
    stack = []
    res = 0
    pos = 0
    
    while pos < len(i_heights):
        if not stack or i_heights[stack[-1]] <= i_heights[pos]:
            stack.append(pos)
            pos += 1
        else:
            top = stack.pop()
            w = pos if not stack else pos - stack[-1] - 1
            area_with_top = i_heights[top] * w
            res = max(res, area_with_top)
    while stack:
        top = stack.pop()
        w = pos if not stack else pos - stack[-1] - 1
        area_with_top = i_heights[top] * w
        res = max(res, area_with_top)
    return res

n = int(raw_input().strip())
h = map(int, raw_input().strip().split())
print max_area(h)

