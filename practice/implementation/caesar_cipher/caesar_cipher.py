#!/bin/python

def encrypt(m, k):
    if m >= 'a' and m <= 'z':
        d = ord(m) - ord('a')
        d += k
        d %= 26
        d += ord('a')
        return chr(d)
    elif m >= 'A' and m <= 'Z':
        d = ord(m) - ord('A')
        d += k
        d %= 26
        d += ord('A')
        return chr(d)
    return m

def encrypt_char(k):
    def util(m):
        return encrypt(m, k)
    return util

n = int(raw_input().strip())
s = raw_input().strip()
k = int(raw_input().strip())

cipher = map(encrypt_char(k), s)
print ''.join(cipher)

