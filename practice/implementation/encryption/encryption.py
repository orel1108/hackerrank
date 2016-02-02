#!/bin/python
import math
import sys

message = raw_input().strip()
n = len(message)

a = int(math.sqrt(n))
width = a if a * a == n else a + 1

height = n // width
if width * height < n:
    height += 1
    
cipher = ''
for ROW in range(width):
    for COL in range(height):
        if ROW + COL * width < n:
            cipher += message[ROW + COL * width]
    if ROW < width - 1:
        cipher += ' '
print cipher

