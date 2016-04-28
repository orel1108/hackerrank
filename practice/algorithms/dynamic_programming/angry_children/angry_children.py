#!/usr/bin/env python

n = int(raw_input().strip())
k = int(raw_input().strip())
candies = []
for _ in range(n):
    candies.append(int(raw_input().strip()))

candies.sort()

ans = 10 ** 20
s = (k - 1) * candies[k - 1]
for POS in range(k - 1):
    s += (2 * POS + 1 - k) * candies[POS]

part_sums = [0]
for POS in range(n):
    part_sums.append(part_sums[-1] + candies[POS])
    
for POS in range(n - k):
    if s < ans:
        ans = s
    s += (k - 1) * (candies[POS + k] + candies[POS])
    s -= 2 * (part_sums[k + POS] - part_sums[POS + 1])
    
if s < ans:
    ans = s
print ans

