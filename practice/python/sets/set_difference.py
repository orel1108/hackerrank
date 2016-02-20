#!/usr/bin/env python

a = input()
A = set(map(int, raw_input().strip().split()))

b = input()
B = set(map(int, raw_input().strip().split()))

print len(A.difference(B))

