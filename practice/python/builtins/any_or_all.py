#!/usr/bin/env python

def is_palindrom(i_val):
    s = str(i_val)
    if len(s) < 2:
        return True
    else:
        n = len(s)
        for cnt in range(n // 2):
            if s[cnt] != s[n - 1 - cnt]:
                return False
    return True

n = int(raw_input().strip())
a = map(int, raw_input().strip().split())
print all([x > 0 for x in a]) and any([is_palindrom(x) for x in a])

