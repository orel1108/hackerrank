#!/usr/bin/env python

n = int(raw_input().strip())
if n % 2 == 1:
    print "Weird"
elif n >= 2 and n <= 5:
    print "Not Weird"
elif n >= 6 and n <= 20:
    print "Weird"
else:
    print "Not Weird"

