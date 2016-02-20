#!/usr/bin/env python

srcstr = raw_input().strip()
substr = raw_input().strip()

cnt = 0
if len(srcstr) < len(substr):
    print cnt
else:
    ans = False
    for i in range(len(srcstr) - len(substr) + 1):
        if substr[0] == srcstr[i]:
            ans = True
            for j in range(len(substr)):
                if substr[j] != srcstr[i + j]:
                    ans = False
                    break
            if ans == True:
                cnt += 1
    print cnt

