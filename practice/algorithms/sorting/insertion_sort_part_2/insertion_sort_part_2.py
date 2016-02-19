#!/usr/bin/env python

def insertionSort(ar):
    n = len(ar)
    for i in range(1, n):
        j = i
        while j > 0 and ar[i] < ar[j - 1]:
            j -= 1
        v = ar[i]
        for k in range(i, j, -1):
            ar[k] = ar[k - 1]
        ar[j] = v
        
        for VAL in ar:
            print VAL,
        print
    return ""

m = input()
ar = [int(i) for i in raw_input().strip().split()]
insertionSort(ar)

