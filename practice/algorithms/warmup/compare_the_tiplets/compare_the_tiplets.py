#!/usr/bin/env python

def score(i_pair):
    if i_pair[0] > i_pair[1]:
        return 1, 0
    if i_pair[0] < i_pair[1]:
        return 0, 1
    return 0, 0

a = map(int, raw_input().strip().split())
b = map(int, raw_input().strip().split())
c = reduce(lambda x, y: [x[0] + y[0], x[1] + y[1]], map(lambda pair: score(pair), zip(a, b)), [0, 0])
print c[0], c[1]

