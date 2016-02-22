#!/usr/bin/env python

import re
r_and = re.compile(r' &{2} ')
r_or = re.compile(r' \|{2} ')

n = int(raw_input().strip())
text = ''
for _ in range(n):
    line = raw_input().strip()
    text += line + '\n'

text = r_and.sub(' and ', text)
text = r_or.sub(' or ', text)
text = r_and.sub(' and ', text)
text = r_or.sub(' or ', text)
print text

