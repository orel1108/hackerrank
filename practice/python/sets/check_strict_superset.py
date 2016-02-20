#!/usr/bin/env python

A = set(map(int, raw_input().strip().split()))
n = int(raw_input().strip())
s = []
for _ in range(n):
    B = set(map(int, raw_input().strip().split()))
    s.append(B)
    
cnt = 0
while cnt < n:
    B = s[cnt]
    if not (A.difference(B) and not B.difference(A)):
        break
    cnt += 1
print True if cnt == n else False

