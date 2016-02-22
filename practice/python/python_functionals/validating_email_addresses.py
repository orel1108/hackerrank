#!/usr/bin/env python

import re

def is_valid(i_address):
    match = re.search(r"^[a-zA-Z0-9_-]+\@[a-zA-Z0-9.]+\.[a-zA-Z]{,3}$", i_address)
    return True if match else False

n = int(raw_input().strip())
addr = []
for _ in range(n):
    addr.append(raw_input().strip())
    
valid_addr = list(filter(lambda ADRR: is_valid(ADRR), addr))
print sorted(valid_addr)

