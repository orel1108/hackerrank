#!/usr/bin/env python

n = int(raw_input().strip())
a = map(int, raw_input().strip().split())

if a == sorted(a):
    print 'yes'
else:
    d = []
    begin = 0
    while begin < n - 1 and a[begin] < a[begin + 1]:
        begin += 1
    end = n - 1
    while end > 0 and a[end] > a[end - 1]:
        end -= 1
    a[begin], a[end] = a[end], a[begin]
    if a == sorted(a):
        print 'yes'
        print 'swap', begin + 1, end + 1
    else:
        a[begin], a[end] = a[end], a[begin]
        a = a[:begin] + list(reversed(a[begin:end + 1])) + a[end + 1:]
        if a == sorted(a):
            print 'yes'
            print 'reverse', begin + 1, end + 1
        else:
            print 'no'

