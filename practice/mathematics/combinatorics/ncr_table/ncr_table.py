#!/usr/bin/env python

pascal_triangle = [
    [1,],
    [1, 1],
]

for _ in xrange(1000):
    last_row = pascal_triangle[-1]
    new_row = [1]
    for pos in xrange(len(last_row) - 1):
        new_row.append((last_row[pos] + last_row[pos + 1]) % 1000000000)
    new_row.append(1)
    pascal_triangle.append(new_row)

t = int(raw_input().strip())
for _ in xrange(t):
    n = int(raw_input().strip())
    for VAL in pascal_triangle[n]:
        print VAL,
    print

