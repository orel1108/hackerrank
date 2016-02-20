#!/usr/bin/env python

alphabert  = [chr(VAL) for VAL in range(97, 123)]
ralphabert = [chr(VAL) for VAL in range(122, 96, -1)]

n = int(raw_input().strip())
if n == 1:
    print 'a'
else:
    w = 4 * n - 3

    for cnt in range(n - 1, -1, -1):
        left   = '-'.join(alphabert[cnt + 1:n])
        right  = '-'.join(alphabert[cnt + 1:n])
        center = alphabert[cnt]
        print (''.join(reversed(right)) + '-' + center + '-' + left).center(w, '-')

    for cnt in range(1, n):
        left   = '-'.join(alphabert[cnt + 1:n])
        right  = '-'.join(alphabert[cnt + 1:n])
        center = alphabert[cnt]
        print (''.join(reversed(right)) + '-' + center + '-' + left).center(w, '-')

