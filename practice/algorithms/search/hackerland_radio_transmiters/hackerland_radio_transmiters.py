#!/usr/bin/env python

n, k = map(int, raw_input().strip().split())
x = map(int, raw_input().strip().split())
x.sort()

cnt = 0
curr_pos = 0
while curr_pos < n:
    prev_pos = curr_pos
    while curr_pos < n and x[curr_pos] - x[prev_pos] <= k:
        curr_pos += 1
    
    curr_pos -= 1
    cnt += 1

    prev_pos = curr_pos
    while curr_pos < n and x[curr_pos] - x[prev_pos] <= k:
        curr_pos += 1
print cnt

