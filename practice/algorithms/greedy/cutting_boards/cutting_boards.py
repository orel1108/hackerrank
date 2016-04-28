#!/usr/bin/env python

t = int(raw_input().strip())
for _ in range(t):
    m, n = map(int, raw_input().strip().split())
    
    y_values = sorted(map(int, raw_input().strip().split()), reverse=True)
    y_values.append(0)
    
    x_values = sorted(map(int, raw_input().strip().split()), reverse=True)
    x_values.append(0)
    
    y_segments = 1
    x_segments = 1
    cost = 0
    x_counter = 0
    y_counter = 0
    for __ in range(m + n - 2):
        if y_values[y_counter] >= x_values[x_counter]:
            cost += y_values[y_counter] * x_segments
            y_segments += 1
            y_counter += 1
        else:
            cost += x_values[x_counter] * y_segments
            x_segments += 1
            x_counter += 1
        if cost >= 1000000007:
            cost %= 1000000007
    print cost

