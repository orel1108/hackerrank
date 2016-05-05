#!/usr/bin/env python

def numVar(i_n):
    if i_n == 1 or i_n == 2 or i_n == 3:
        return 1
    if i_n == 4:
        return 2
    return numVar(i_n - 1) + numVar(i_n - 4)

def sieve(i_n):
    is_prime = [True for _ in range(i_n + 1)]
    is_prime[0] = False
    is_prime[1] = False
    
    i = 2
    while i * i <= i_n:
        if is_prime[i]:
            j = i * i
            while j <= i_n:
                is_prime[j] = False
                j += i
        i += 1
    return is_prime

mx_num = numVar(40)
prime = sieve(mx_num)

for POS in range(mx_num):
    prime[POS + 1] += prime[POS]
    
t = int(raw_input().strip())
for _ in range(t):
    n = int(raw_input().strip())
    num_variants = numVar(n)
    print prime[num_variants]

