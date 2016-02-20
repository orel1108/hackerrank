#!/usr/bin/env python

a = input()
A = set(map(int, raw_input().strip().split()))

n = input()
for _ in range(n):
    instr = raw_input().strip().split()
    N = set(map(int, raw_input().strip().split()))
    if instr[0] == 'update':
        A.update(N)
    elif instr[0] == 'intersection_update':
        A.intersection_update(N)
    elif instr[0] == 'difference_update':
        A.difference_update(N)
    elif instr[0] == 'symmetric_difference_update':
        A.symmetric_difference_update(N)
print sum(A)

