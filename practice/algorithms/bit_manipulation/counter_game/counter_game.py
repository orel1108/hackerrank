#!/usr/bin/env python

A = [1 << POS for POS in range(65)]

def num_steps(i_n):
    steps = 0
    while True:
        pos = 0
        while pos < len(A):
            if A[pos] == i_n:
                steps += pos + 1
                return steps
            if A[pos] > i_n:
                k = i_n // A[pos - 1]
                i_n -= k * A[pos - 1]
                steps += k
                break
            pos += 1
    return steps
        
t = int(raw_input().strip())
for _ in xrange(t):
    n = int(raw_input().strip())
    d = num_steps(n)
    if d % 2 == 1:
        print 'Richard'
    else:
        print 'Louise'

