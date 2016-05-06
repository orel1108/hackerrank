#!/usr/bin/env python

def decrypt(i_enc, i_n, i_k):
    bits = map(int, i_enc)
    d = [bits[0]]
    for K in range(1, min(i_k, i_n)):
        d.append(bits[K - 1] ^ bits[K])
    for K in range(i_k, i_n):
        d.append(bits[K - 1] ^ bits[K] ^ d[K - i_k])
    return ''.join(map(str, d))

n, k = map(int, raw_input().strip().split())
e = raw_input().strip()
print decrypt(e, n, k)

