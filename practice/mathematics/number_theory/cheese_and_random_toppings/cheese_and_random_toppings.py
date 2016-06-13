#!/usr/bin/env python

SMALL_PRIMES = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]

def inverse_mod(i_value, i_prime):
    return pow(i_value, i_prime - 2, i_prime)

def crt(i_a, i_prime_list):
    N = reduce(lambda x, y: x * y, i_prime_list, 1)
    
    x = 0
    for CNT in range(len(i_prime_list)):
        d = N // i_prime_list[CNT]
        s = i_a[CNT] * d * inverse_mod(d, i_prime_list[CNT])
        x += s
    return x % N

def decompose(i_value, i_prime):
    coeffs = []
    while i_value > 0:
        coeffs.append(i_value % i_prime)
        i_value //= i_prime
    return coeffs

def binom_mod(i_n, i_m, i_prime):
    if i_n < i_m:
        return 0
    if i_m == 0:
        return 1
    if i_m == i_n:
        return 1
    num = 1
    den = 1
    for CNT in range(i_n - i_m):
        num *= (i_n - CNT)
        den *= (i_n - i_m - CNT)
    num //= den
    return num % i_prime

def lucas(i_n, i_m, i_prime):
    n_coeffs = decompose(i_n, i_prime)
    m_coeffs = decompose(i_m, i_prime)
    diff = len(n_coeffs) - len(m_coeffs)
    if diff > 0:
        m_coeffs.extend([0 for _ in range(diff)])
    r = 1
    for CNT in range(len(n_coeffs)):
        r *= binom_mod(n_coeffs[CNT], m_coeffs[CNT], i_prime)
    return r % i_prime

t = int(raw_input().strip())
for _ in range(t):
    n, r, m = map(int, raw_input().strip().split())
    a = []
    p = []
    for PRIME in SMALL_PRIMES:
        if m % PRIME == 0:
            v = lucas(n, r, PRIME)
            a.append(v)
            p.append(PRIME)
    print crt(a, p)

