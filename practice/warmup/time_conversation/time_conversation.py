#!/bin/python

time = raw_input().strip()
L = time[:-2].split(':')
if L[0] == '12':
    if time[-2:] == 'AM':
        L[0] = '00'
else:
    if time[-2:] == 'PM':
        L[0] = str(12 + int(L[0]))
print ':'.join(L)

