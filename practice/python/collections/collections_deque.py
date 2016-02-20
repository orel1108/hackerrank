#!/usr/bin/env python

from collections import deque

dq = deque()
n = int(raw_input().strip())

for _ in range(n):
    comm = raw_input().strip().split()
    if comm[0] == 'append':
        dq.append(int(comm[1]))
    elif comm[0] == 'appendleft':
        dq.appendleft(int(comm[1]))
    elif dq:
        if comm[0] == 'pop':
            dq.pop()
        elif comm[0] == 'popleft':
            dq.popleft()
while dq:
    print dq.popleft(),

