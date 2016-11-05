#!/usr/bin/env python

win_pos = [False, False, True, True, True, True]
for POS in xrange(6, 101):
    r = win_pos[POS - 5] and win_pos[POS - 3] and win_pos[POS - 2]
    win_pos.append(not r)
    
t = int(raw_input().strip())
for _ in xrange(t):
    n = int(raw_input().strip())
    if win_pos[n]:
        print "First"
    else:
        print "Second"

