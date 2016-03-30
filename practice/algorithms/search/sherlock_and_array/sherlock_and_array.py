#!/usr/bin/env python

t = int(raw_input().strip())

for _ in range(t):
    n = int(raw_input().strip())
    arr = map(int, raw_input().strip().split())
    
    left_counter = 0
    right_counter = len(arr) - 1
    left_sum = 0
    right_sum = 0
    while left_counter < right_counter:
        if left_sum <= right_sum:
            left_sum += arr[left_counter]
            left_counter += 1
        else:
            right_sum += arr[right_counter]
            right_counter -= 1
    if left_counter == right_counter and left_sum == right_sum:
        print "YES"
    else:
        print "NO"

