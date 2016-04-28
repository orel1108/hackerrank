#!/usr/bin/env python

n, h, i = map(int, raw_input().strip().split())

t = [[0 for _ in range(n)] for __ in range(h + i)]
m = [[0 for _ in range(n)] for __ in range(h)]

for N in range(n):
    a = map(int, raw_input().strip().split())
    for K in range(a[0]):
        m[a[K + 1] - 1][N] += 1

f_max = [[0, 0] for _ in range(h + i)]
for F in range(h - 1, -1, -1):
    for B in range(n):
        if B != f_max[F][0]:
            t[F][B] = m[F][B] + max(t[F + 1][B], f_max[F + i][1])
        else:
            t[F][B] = m[F][B] + max([t[F + 1][B]] + [t[F + i][B_1] for B_1 in range(n) if B_1 != B])
        if t[F][B] > f_max[F][1]:
            f_max[F][1] = t[F][B]
            f_max[F][0] = B

print max(t[0])

