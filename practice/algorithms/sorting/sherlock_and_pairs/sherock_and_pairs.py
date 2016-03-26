#!/usr/bin/env python

t = int(raw_input().strip())

for _ in range(t):
    n = int(raw_input().strip())
    arr = sorted(map(int, raw_input().strip().split()))
    counter = 0
    result = 0
    while counter < len(arr):
        entry_counter = 0
        while counter + entry_counter < len(arr) and arr[counter] == arr[counter + entry_counter]:
            entry_counter += 1
        counter += entry_counter
        result += entry_counter * (entry_counter - 1)

    print result

