#!/usr/bin/env python

def rtInsertionSort(a, n):
    rt = 0
    for pos in range(1, n):
        j = pos
        v = a[pos]
        while j > 0 and a[j - 1] > a[pos]:
            j -= 1
            rt += 1
        for k in range(pos, j, -1):
            a[k] = a[k - 1]
        a[j] = v
    return rt

n = int(raw_input().strip())
a = map(int, raw_input().strip().split())

print rtInsertionSort(a, n)
