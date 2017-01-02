#!/usr/bin/env python

def getPosition(i_chr):
    return ord(i_chr) - ord('a')

h = map(int, raw_input().strip().split())
p = map(getPosition, raw_input().strip())
height = 0
for POS in p:
    height = max(height, h[POS])
print height * len(p)

