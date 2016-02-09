#!/usr/bin/env python

from __future__ import print_function
import sys

print(''.join(map(str, range(1, int(raw_input()) + 1))), sep='', end='\n', file=sys.stdout)
