#!/usr/bin/env python

def solve(i_perm):
    x = len(i_perm)
    s = pow(2, x)
    dp = [False for _ in range(s)]
    for SUBSET in range(1, s):
        ss = list(bin(SUBSET)[2:])
        ss = ['0' for _ in range(x - len(ss))] + ss
        arr = []
        for POS in range(len(ss)):
            if ss[POS] == '1':
                arr.append(i_perm[POS])
        if arr == sorted(arr):
            dp[SUBSET] = False
        else:
            pos = 0
            while pos < len(ss):
                if ss[pos] == '1':
                    ss[pos] = '0'
                    ns = ''.join(ss)
                    ss[pos] = '1'
                    np = int(ns, 2)
                    if not dp[np]:
                        dp[SUBSET] = True
                        break
                pos += 1
            if pos == len(ss):
                dp[SUBSET] = False
    return dp[-1]
    

t = int(raw_input().strip())
for _ in range(t):
    n = int(raw_input().strip())
    p = map(int, raw_input().strip().split())
    if solve(p):
        print "Alice"
    else:
        print "Bob"

