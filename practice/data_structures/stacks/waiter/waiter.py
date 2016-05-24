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

PRIMES = sieve(10000)

n, q = map(int, raw_input().strip().split())
a = list(reversed(map(int, raw_input().strip().split())))
r = []
prime_cnt = 0
for _ in xrange(q):
    n = len(a)
    for __ in xrange(n):
        top = a.pop()
        if top % PRIMES[prime_cnt] == 0:
            print top
        else:
            r.append(top)
    a = list(r)
    r = []
    prime_cnt += 1
while a:
    print a.pop(0)

