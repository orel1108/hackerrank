#!/bin/python

n = int(raw_input().strip())
matrix = []
for _ in range(n):
    row = map(int, raw_input().strip().split(' '))
    matrix.append(row)
    
diag = sum([matrix[POS][POS] for POS in range(n)])
codiag = sum([matrix[n - 1 - POS][POS] for POS in range(n)])
    
print abs(diag - codiag)

