#!/usr/bin/env python

import email.utils
import re

n = int(raw_input())
for _ in range(n):
    r = raw_input()
    p = email.utils.parseaddr(r)
    if re.search('(^[a-zA-Z])([a-zA-Z0-9._-]*)@([a-zA-Z]+)[.][a-zA-Z]{1,3}$', p[1]):
        print email.utils.formataddr(p)

