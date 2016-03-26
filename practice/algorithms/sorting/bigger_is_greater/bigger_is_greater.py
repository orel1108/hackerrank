#!/usr/bin/env python

def next_permutation(s):
    for pos in range(len(s) - 1, 0, -1):
        if s[pos] > s[pos - 1]:
            break
    else:
        return []
    pos -= 1
    for j in reversed(range(pos + 1, len(s))):
        if s[j] > s[pos]: break
    s[pos], s[j] = s[j], s[pos]
    s[pos + 1:] = reversed(s[pos + 1:])
    return s

t = int(raw_input().strip())
for _ in range(t):
    s = list(raw_input().strip())
    r = next_permutation(s)
    if r:
        print ''.join(r)
    else:
        print "no answer"

