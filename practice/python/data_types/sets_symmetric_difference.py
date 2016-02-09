#!/usr/bin/env python


n = int(raw_input().strip())
mval = set(map(int, raw_input().split()))

n = int(raw_input().strip())
nval = set(map(int, raw_input().split()))

diff1 = mval.difference(nval)
diff2 = nval.difference(mval)

res = diff1.union(diff2)
sres = sorted(list(res))
for item in sres:
    print item
