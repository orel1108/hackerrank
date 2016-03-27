#!/usr/bin/env python

def partition(i_arr, i_low, i_high):
    pivot = i_arr[i_high]
    pos = i_low
    for IPOS in range(i_low, i_high):
        if i_arr[IPOS] <= pivot:
            i_arr[pos], i_arr[IPOS] = i_arr[IPOS], i_arr[pos]
            pos += 1
    i_arr[pos], i_arr[i_high] = i_arr[i_high], i_arr[pos]
    for VAL in i_arr:
        print VAL,
    print
    return pos

def quicksort_in_place(i_arr, i_low, i_high):
    if i_low < i_high:
        p = partition(i_arr, i_low, i_high)
        quicksort_in_place(i_arr, i_low, p - 1)
        quicksort_in_place(i_arr, p + 1, i_high)

n = int(raw_input().strip())
a = map(int, raw_input().strip().split())
quicksort_in_place(a, 0, n - 1)

