#!/usr/bin/env python

X = input()
Y = input()
Z = input()
N = input()

res = [[i, j, k] for i in range(X + 1) for j in range(Y + 1) for k in range(Z + 1) if sum([ i, j, k ]) != N]
print res
