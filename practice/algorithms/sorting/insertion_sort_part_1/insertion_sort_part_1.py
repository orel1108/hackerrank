#!/usr/bin/env python

def insertionSort(ar):
    v = ar[-1]
    j = len(ar) - 1
    while j > 0 and ar[j - 1] > v:
        ar[j] = ar[j - 1]
        j -= 1
        for VAL in ar:
            print VAL,
        print
    ar[j] = v
    for VAL in ar:
        print VAL,
    print    
    return ""

m = input()
ar = [int(i) for i in raw_input().strip().split()]
insertionSort(ar)

