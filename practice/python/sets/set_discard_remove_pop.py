#!/usr/bin/env python

n = input()
s = set(map(int, raw_input().strip().split())) 
q = input()
for _ in range(q):
    comm = raw_input().strip().split()
    if comm[0] == 'remove':
        s.remove(int(comm[1]))
    elif comm[0] == 'discard':
        s.discard(int(comm[1]))
    elif comm[0] == 'pop':
        s.pop()
print sum(s)

