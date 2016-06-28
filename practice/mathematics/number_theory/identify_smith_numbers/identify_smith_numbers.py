#!/usr/bin/env python

def sum_digits(i_val):
    return sum(map(int, str(i_val)))

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
PRIMES = sieve(min(10000000, n + 1))

d = sum_digits(n)
s = 0

for P in PRIMES:
    if n < P:
        break
    if n % P == 0:
        t = sum_digits(P)
        while n % P == 0:
            s += t
            n //= P
    if s > d:
        break
if s == d:
    print 1
else:
    print 0

