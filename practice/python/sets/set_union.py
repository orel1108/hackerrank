#!/usr/bin/env python

a = input()
A = set(map(int, raw_input().split()))

b = input()
B = set(map(int, raw_input().split()))

print len(A.union(B))

