#!/usr/bin/env python

def f(i_k):
    if i_k == 0:
        return 1
    if i_k == 1:
        return 3

    m = [
        [6, -1],
        [1, 0]
    ]
    res_m = [
        [1, 0],
        [0, 1]
    ]

    tmp = [
        [0, 0],
        [0, 0]
    ]
    while i_k > 0:
        if i_k & 1 == 1:
            tmp[0][0] = (res_m[0][0] * m[0][0] + res_m[0][1] * m[1][0]) % 1000000007
            tmp[0][1] = (res_m[0][0] * m[0][1] + res_m[0][1] * m[1][1]) % 1000000007
            tmp[1][0] = (res_m[1][0] * m[0][0] + res_m[1][1] * m[1][0]) % 1000000007
            tmp[1][1] = (res_m[1][0] * m[0][1] + res_m[1][1] * m[1][1]) % 1000000007

            res_m[0][0] = tmp[0][0]
            res_m[0][1] = tmp[0][1]
            res_m[1][0] = tmp[1][0]
            res_m[1][1] = tmp[1][1]

        i_k >>= 1

        tmp[0][0] = (m[0][0] * m[0][0] + m[0][1] * m[1][0]) % 1000000007
        tmp[0][1] = (m[0][0] * m[0][1] + m[0][1] * m[1][1]) % 1000000007
        tmp[1][0] = (m[1][0] * m[0][0] + m[1][1] * m[1][0]) % 1000000007
        tmp[1][1] = (m[1][0] * m[0][1] + m[1][1] * m[1][1]) % 1000000007

        m[0][0] = tmp[0][0]
        m[0][1] = tmp[0][1]
        m[1][0] = tmp[1][0]
        m[1][1] = tmp[1][1]

    return 3 * res_m[1][0] + res_m[1][1]


n = int(raw_input().strip())
a = map(int, raw_input().strip().split())

prod = 1

for N in xrange(n):
    prod *= (2 * f(a[N]))
    if prod >= 1000000007:
        prod %= 1000000007
res = prod % 1000000007
print res

