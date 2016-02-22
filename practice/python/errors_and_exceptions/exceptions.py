#!/usr/bin/env python

t = int(raw_input().strip())
for _ in range(t):
    a, b = raw_input().strip().split()
    c = 0
    try:
        a = int(a)
        b = int(b)
        c = a / b
        print c
    except ValueError as ve:
        print "Error Code:", ve
    except ZeroDivisionError as zd:
        print "Error Code:", zd

