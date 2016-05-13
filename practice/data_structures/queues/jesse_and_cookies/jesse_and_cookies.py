#!/usr/bin/env python

import heapq

def solve(i_s, i_k):
    if len(i_s) == 1:
        if i_s[0] >= i_k:
            return 0
        return -1
    
    q = []
    for VAL in i_s:
        heapq.heappush(q, VAL)        
    cnt = 0
    while True:
        if len(q) == 1:
            if q[0] >= i_k:
                return cnt
            return -1
        else:
            a = heapq.heappop(q)
            if a >= i_k:
                return cnt
            b = heapq.heappop(q)
            heapq.heappush(q, a + 2 * b)
            cnt += 1
    return cnt

n, k = map(int, raw_input().strip().split())
s = map(int, raw_input().strip().split())
print solve(s, k)

