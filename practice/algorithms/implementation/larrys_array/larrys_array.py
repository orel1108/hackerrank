#!/usr/bin/env python

def rotate_triple(i_a, i_pos):
    tmp = i_a[i_pos]
    i_a[i_pos] = i_a[i_pos + 1]
    i_a[i_pos + 1] = i_a[i_pos + 2]
    i_a[i_pos + 2] = tmp

def set_min_correct(i_arr, i_pos):
    m = min(i_arr[i_pos:])
    p = i_arr.index(m)
    while p > i_pos:
        if p == i_pos + 1:
            rotate_triple(i_arr, p - 1)
            p -= 1
        else:
            rotate_triple(i_arr, p - 2)
            rotate_triple(i_arr, p - 2)
            p -= 2

t = int(raw_input().strip())
for _ in range(t):
    n = int(raw_input().strip())
    a = map(int, raw_input().strip().split())
    for POS in range(n - 2):
        set_min_correct(a, POS)
    b = a[n - 3 :]
    if b == sorted(b):
        print "YES"
    else:
        print "NO"

