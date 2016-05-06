#!/usr/bin/env python

def find_decomp(i_n):
    d = {1:set([(1,)])}
    for VAL in range(2, i_n + 1):
        d[VAL] = set([(VAL,)])
        for K in range(1, (VAL + 1) // 2):
            d[VAL].add((K, VAL - K))
            for L in d[K]:
                for R in d[VAL - K]:
                    x = tuple(sorted(set(L).union(set(R))))
                    if sum(x) == VAL:
                        d[VAL].add(x)
    return d

def grundy(i_n):
    res = [0 for _ in range(i_n + 1)]
    for VAL in range(3, i_n + 1):
        s = set()
        for DEC in DECOMPS[VAL]:
            if len(DEC) > 1:
                x = 0
                for D in DEC:
                    x ^= res[D]
                s.add(x)
        while res[VAL] in s:
            res[VAL] += 1
    return res

MAX_N = 50
DECOMPS = find_decomp(MAX_N)
GRUNDY = grundy(MAX_N)

t = int(raw_input().strip())
for _ in range(t):
    n = int(raw_input().strip())
    a = map(int, raw_input().strip().split())
    x = 0
    for VAL in a:
        x ^= GRUNDY[VAL]
    if x == 0:
        print "BOB"
    else:
        print "ALICE"

