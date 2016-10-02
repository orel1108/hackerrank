#!/usr/bin/env python

s = raw_input()
r = []
for CHR in s:
    if len(r) > 0 and CHR == r[-1]:
        r.pop()
    else:
        r.append(CHR)
if r:
    print ''.join(r)
else:
    print "Empty String"

