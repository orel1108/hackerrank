#!/usr/bin/env python

s = raw_input().strip()
LEN = len(s)

Player1 = 0
Player2 = 0

VOWELS = 'AEIOU'

for POS in range(LEN):
    if s[POS] in VOWELS:
        Player2 += (LEN - POS)
    else:
        Player1 += (LEN - POS)
if Player1 > Player2:
    print 'Stuart', Player1
elif Player1 < Player2:
    print 'Kevin', Player2
else:
    print 'Draw'

