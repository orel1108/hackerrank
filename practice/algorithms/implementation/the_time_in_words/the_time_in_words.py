#!/bin/python

import sys

def to_word(i_h):
    w = ['one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten',
         'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 
         'eighteen', 'nineteen', 'twenty']
    return w[i_h - 1]

h = int(raw_input().strip())
m = int(raw_input().strip())

if m == 0:
    print to_word(h) + ' o\' clock'
elif m == 30:
        print 'half past ' + to_word(h)
elif m < 30:
    if m == 1:
        print 'one minute past ' + to_word(h)
    elif m == 15:
        print 'quarter past '  + to_word(h)
    elif m < 21:
        print to_word(m) + ' minutes past ' + to_word(h)
    elif m < 30:
        print 'twenty ' + to_word(m % 10) + ' minutes past ' + to_word(h)
else:
    m = 60 - m
    if m == 1:
        print 'one to ' + to_word(h + 1)
    elif m == 15:
        print 'quarter to '  + to_word(h + 1)
    elif m < 21:
        print to_word(m) + ' minutes to ' + to_word(h + 1)
    elif m < 30:
        print 'twenty ' + to_word(m % 10) + ' minutes to ' + to_word(h + 1)

