#!/usr/bin/env python

from collections import defaultdict

t = int(raw_input().strip())
for _ in range(t):
    v = map(int, raw_input().strip().split())
    n = v[0]
    if n == 0:
        print 0
    else:
        v = sorted(v[1:])
        teams = defaultdict(list)
        teams[v[0]].append(1)
        keys = set([v[0]])
        for cnt in range(1, len(v)):
            if (v[cnt] - 1) in keys:
                m = teams[v[cnt] - 1][0]
                teams[v[cnt]].append(m + 1)
                teams[v[cnt] - 1].remove(m)
                if not teams[v[cnt] - 1]:
                    keys.discard(v[cnt] - 1)
            else:
                teams[v[cnt]].insert(0, 1)
            keys.add(v[cnt])
        r = n
        for KEY in keys:
            r = min(r, teams[KEY][0])
        print r

