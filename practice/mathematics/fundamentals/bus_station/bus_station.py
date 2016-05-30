#!/usr/bin/env python

import math

def divisorGenerator(i_n):
    divisors = []
    for D in xrange(1, int(math.sqrt(i_n) + 1)):
        if i_n % D == 0:
            divisors.append(D)
            if D != i_n / D:
                divisors.insert(0, i_n / D)
    return divisors

n = int(raw_input().strip())
a = map(int, raw_input().strip().split())

sizes = []
max_size = sum(a)

divisors = divisorGenerator(max_size)

for D in divisors:
    counter = 0
    current_size = 0
    while counter < n:
        current_size += a[counter]
        counter += 1
        if current_size == D:
            current_size = 0
        elif current_size > D:
            break
    if counter == n and current_size == 0:
        sizes.append(D)
        
for item in sorted(sizes):
    print item,

