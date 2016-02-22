#!/usr/bin/env python

import re

num = raw_input().strip()
match = re.match(r'^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$', num)
print True if match else False

