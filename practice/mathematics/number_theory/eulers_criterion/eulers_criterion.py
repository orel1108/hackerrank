#!/usr/bin/env python

def euler(i_a, i_p):
    x = pow(i_a, (i_p - 1) // 2, i_p)
    if x == 1:
        return True
    else:
        return False
    
t = int(raw_input().strip())
for _ in xrange(t):
    a, p = map(int, raw_input().strip().split())
    if p == 2 or a == 0 or euler(a, p):
        print 'YES'
    else:
        print 'NO'

