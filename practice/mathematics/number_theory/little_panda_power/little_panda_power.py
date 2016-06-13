#!/usr/bin/env python

from fractions import gcd

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
    return [CNT for CNT in range(2, i_n + 1) if is_prime[CNT]], is_prime

PRIMES, IS_PRIME = sieve(1000001)

PHI = [0, 1]
for VAL in range(2, 1000001):
    if IS_PRIME[VAL]:
        PHI.append(VAL - 1)
    else:
        for P in PRIMES:
            if VAL % P == 0:
                cnt = 0
                n = VAL
                while n % P == 0:
                    cnt += 1
                    n //= P
                PHI.append(P ** (cnt - 1) * (P - 1) * PHI[n])
                break

t = int(raw_input().strip())
for _ in xrange(t):
    a, b, x = map(int, raw_input().strip().split())
    if b >= 0:
        print pow(a, b, x)
    else:
        print pow(pow(a, PHI[x] - 1, x), abs(b), x)

