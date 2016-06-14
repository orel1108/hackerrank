#!/usr/bin/env python

from fractions import gcd

def count2(i_n):
    cnt = 0
    while i_n > 0 and i_n % 2 == 0:
        cnt += 1
        i_n //= 2
    return cnt

def count5(i_n):
    cnt = 0
    while i_n > 0 and i_n % 5 == 0:
        cnt += 1
        i_n //= 5
    return cnt

def find_period_len(i_n):
    vals = []
    vals_set = set()
    d = 1
    cnt = 0
    while True:
        d *= 10
        d %= i_n
        if d == 0:
            return 0
        cnt += 1
        if d in vals_set:
            return cnt - vals.index(d) - 1
        vals.append(d)
        vals_set.add(d)

t = int(raw_input().strip())
for _ in xrange(t):
    x = int(raw_input().strip())
    c2 = count2(x)
    c5 = count5(x)
    m = max(c2 - 2, c5)
    d = gcd(x, 2 ** (m + 2) * 5 ** m)
    x //= d
    n = 1
    r = 1
    if x > 1:
        n = find_period_len(x)
        r = n
        while (10 ** r - 1) // 9 % x != 0:
            r += n
    print 2 * r + m

