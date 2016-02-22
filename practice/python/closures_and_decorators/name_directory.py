#!/usr/bin/env python

from operator import itemgetter
from itertools import groupby

n = int(raw_input().strip())
names = []
for _ in range(n):
    line = raw_input().strip().split()
    nl = [line[0], line[1], int(line[2]), line[3]]
    names.append(nl)
    
names.sort(key = itemgetter(2))

for elt, items in groupby(names, itemgetter(2)):
    for row in items:
        if str(row[ 3 ]) == 'M\r' or str(row[ 3 ]) == 'M':
            print 'Mr.',
        else:
            print 'Ms.',
        print row[0], row[1]

