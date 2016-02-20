#!/usr/bin/env python

n = int(raw_input().strip())

MAX_LEN = len(bin(n)) - 2

for VAL in range(1, n + 1):
    print str(VAL).rjust(MAX_LEN), 
    print str(oct(VAL)[1:]).rjust(MAX_LEN), 
    print str(hex(VAL)[2:]).upper().rjust(MAX_LEN), 
    print str(bin(VAL)[2:]).rjust(MAX_LEN)

