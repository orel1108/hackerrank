#!/usr/bin/env python

import re

s = raw_input().strip()
for TOK in re.split(r'[,.]', s):
    if TOK:
        print TOK.strip()

