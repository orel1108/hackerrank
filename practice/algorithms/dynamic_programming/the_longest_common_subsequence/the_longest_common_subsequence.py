#!/usr/bin/env python
        
n, m = map(int, raw_input().strip().split())
a = map(int, raw_input().strip().split())
b = map(int, raw_input().strip().split())

c = [[0] * (n + 1) for _ in range(m + 1)]
for row_cnt in range(1, m + 1):
    for col_cnt in range(1, n + 1):
        if a[col_cnt - 1] == b[row_cnt - 1]:
            c[row_cnt][col_cnt] = c[row_cnt - 1][col_cnt - 1] + 1
        else:
            c[row_cnt][col_cnt] = max(c[row_cnt - 1][col_cnt] , c[row_cnt][col_cnt - 1])

result = []
while n != 0 and m != 0:
    if c[m][n] == c[m - 1][n]:
        m -= 1
    elif c[m][n] == c[m][n - 1]:
        n -= 1
    else:
        result.append(b[m - 1])
        n -= 1
        m -= 1

result.reverse()
for item in result:
    print item,

