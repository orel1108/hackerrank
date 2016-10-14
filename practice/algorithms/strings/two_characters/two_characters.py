#!/usr/bin/env python

def copy_substring(i_s, i_c1, i_c2):
    res_s = []
    for CHR in i_s:
        if CHR == i_c1 or CHR == i_c2:
            res_s.append(CHR)
    return res_s

def is_valid(i_s):
    p = []
    for CHR in i_s:
        if len(p) == 0 or p[-1] != CHR:
            p.append(CHR)
        else:
            p.pop()
    return len(i_s) == len(p)
    
n = int(raw_input().strip())
s = raw_input().strip()
c = list(set(s))

if (len(c)) == 1:
    print 0
else:
    res_len = 0
    for POS1 in xrange(len(c)):
        for POS2 in xrange(POS1 + 1, len(c)):
            t = copy_substring(s, c[POS1], c[POS2])
            if is_valid(t):
                res_len = max(res_len, len(t))
    print res_len

