#!/usr/bin/env python

n = int(raw_input().strip())
if n == 0:
    print []
elif n == 1:
    print [0]
elif n == 2:
    print [0, 1]
else:
    ls = [0, 1]
    for i in range(2, n):
        ls.append(ls[i - 1] + ls[i - 2])

    print map(lambda x : x ** 3, ls)

