#!/usr/bin/env python

def find_lis(i_arr):
    if not i_arr:
        return []
    
    p = [0 for _ in range(len(i_arr))]
    u = 0
    v = 0

    b = [0]
    for POS in range(1, len(i_arr)):
        if i_arr[b[len(b) - 1]] < i_arr[POS]:
            p[POS] = b[len(b) - 1]
            b.append(POS)
            continue
        u = 0
        v = len(b)
        while u < v:
            c = (u + v) / 2
            if i_arr[b[c]] < i_arr[POS]:
                u = c + 1
            else:
                v = c
        if i_arr[POS] < i_arr[b[u]]:
            if u > 0:
                p[POS] = b[u - 1]
            b[u] = POS
    
    u = len(b) - 1
    v = b[-1]
    while u > 0:
        b[u] = v
        v = p[v]
        u -= 1
    return b
	
n = int(raw_input().strip())
arr = []
for _ in range(n):
    arr.append(int(raw_input().strip()))

print len(find_lis(arr))

