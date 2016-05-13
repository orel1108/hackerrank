#!/usr/bin/env python

import math
from collections import deque

MAX_N = 10 ** 6
RANGE = range(2, 1001)

FACTORS = {}

def solve(i_n):
    global FACTORS
    q = deque()
    q.append((i_n, 0))
    visited = set()
    
    while q:
        p, d = q.popleft()
        if p > 0:
            if (p - 1) not in visited:
                q.append((p - 1, d + 1))

            if p in FACTORS:
                for FACTOR in FACTORS[p]:
                    if FACTOR not in visited:
                        q.append((FACTOR, d + 1))
                        visited.add(FACTOR)
            else:
                FACTORS[p] = []
                for D in RANGE:
                    if D * D > p:
                        break
                    if p % D == 0:
                        a = p // D
                        FACTORS[p].append(a)
                        if a not in visited:
                            q.append((a, d + 1))
                            visited.add(a)
        else:
            return d

q = int(raw_input().strip())
for _ in xrange(q):
    n = int(raw_input().strip())
    print solve(n)

