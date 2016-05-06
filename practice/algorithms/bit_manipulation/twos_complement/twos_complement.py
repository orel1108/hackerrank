#!/usr/bin/env python

def num_bits(i_val):
    if i_val == 0:
        return 0
    if i_val == 1:
        return 1
    
    bits = bin(i_val)[2:]
    n = len(bits)
    cnt = 0
    for POS in range(n - 1):
        if bits[POS] == '1':
            cnt += (n - POS - 1) * 2 ** (n - POS - 2) + int(bits[POS + 1:], 2) + 1
    if bits[-1] == '1':
        cnt += 1
    return cnt

def num_bits_neg(i_val):
    return 32 * abs(i_val) - num_bits(abs(i_val) - 1)

t = int(raw_input().strip())
for _ in range(t):
    A, B = map(int, raw_input().strip().split())
    if A >= 1:
        print num_bits(B) - num_bits(A - 1)
    elif A == 0:
        print num_bits(B)
    elif B >= 0:
        print num_bits(B) + num_bits_neg(A)
    elif B < -1:
        print num_bits_neg(A) - num_bits_neg(B + 1)
    else:
        print num_bits_neg(A)

