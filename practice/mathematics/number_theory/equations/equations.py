#!/usr/bin/env python

def sieve(i_n):
    is_prime = [True for _ in range(i_n + 1)]
    i = 2
    while i * i <= i_n:
        if is_prime[i]:
            j = i * i
            while j <= i_n:
                is_prime[j] = False
                j += i
        i += 1
    return [CNT for CNT in range(2, i_n + 1) if is_prime[CNT]]

n = int(raw_input().strip())
PRIMES = sieve(1000000)

res = 1
for PRIME in PRIMES:
    p = PRIME
    s = 0
    while n // p > 0:
        s = (s + n // p) % 1000007
        p *= PRIME
    res = (res * (2 * s + 1)) % 1000007
print res

