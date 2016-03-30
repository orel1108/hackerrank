#!/usr/bin/env python

n = int(raw_input().strip())
a = map(int, raw_input().strip().split())
seqA = [0 for _ in range(10000)]
for VAL in a:
    seqA[VAL] += 1
    
m = int(raw_input().strip())
b = map(int, raw_input().strip().split())
seqB = [0 for _ in range(10000)]
for VAL in b:
    seqB[VAL] += 1

for POS in range(10000):
    if seqB[POS] > seqA[POS]:
        print POS,

