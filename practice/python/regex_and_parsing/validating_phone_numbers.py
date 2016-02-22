#!/usr/bin/env python

n = raw_input().strip()
ans = 1
for _ in range(n):
    line = raw_input().strip()
    if len(line) == 10:
        for i in range(10):
            if line[i] not in ['0','1','2','3','4','5','6','7','8','9']:
                print 'NO'
                ans = 0
                break
            else:
                ans = 1
        if ans == 1:
            if line[0] == '9' or line[0] == '8' or line[0] == '7' :
                print 'YES'
            else:
                print 'NO' 
    else:
        print 'NO'

