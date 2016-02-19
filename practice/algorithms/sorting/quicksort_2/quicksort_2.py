#!/usr/bin/env python

def quickSort(ar):
    if len(ar) < 2:
        return ar
    pivot = ar[0]
    left = [item for item in ar if item < pivot]
    right = [item for item in ar if item > pivot]
    left = quickSort(left)
    right = quickSort(right)
    res = left + [pivot] + right
    for item in res:
        print item,
    print
    return res

m = input()
ar = map(int, raw_input().strip().split())
quickSort(ar)

