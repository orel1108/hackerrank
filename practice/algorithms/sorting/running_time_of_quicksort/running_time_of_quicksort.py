#!/usr/bin/env python

SWAP_QUICK = 0
SWAP_INSERT = 0
def partition(A, lo, hi):
    global SWAP_QUICK
    pivot = A[hi]
    i = lo
    for j in range(lo, hi):
        if A[j] <= pivot:
            A[i], A[j] = A[j], A[i]
            i += 1
            SWAP_QUICK += 1
    A[i], A[hi] = A[hi], A[i]
    SWAP_QUICK += 1
    return i

def quicksort_in_place(A, lo, hi):
    if lo < hi:
        p = partition(A, lo, hi)
        quicksort_in_place(A, lo, p - 1)
        quicksort_in_place(A, p + 1, hi)
        
def insertion_sort(A):
    global SWAP_INSERT
    for POS in range(1, len(A)):
        curr_val = A[POS]
        position = POS
        while position > 0 and A[position - 1] > curr_val:
            A[position] = A[position - 1]
            position = position - 1
            SWAP_INSERT += 1
        A[position] = curr_val

n = int(raw_input())
a = map(int, raw_input().split())
b = [VAL for VAL in a]
quicksort_in_place(a, 0, n - 1)
insertion_sort(b)
print SWAP_INSERT - SWAP_QUICK

