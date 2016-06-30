#!/usr/bin/env python

MOD = 10 ** 9 + 7

n = int(raw_input().strip())
a = map(int, raw_input().strip().split())
v = map(lambda x: pow(2, x, MOD), a)
print reduce(lambda x, y: x * (y + 1) % MOD, v, 1) - 1


