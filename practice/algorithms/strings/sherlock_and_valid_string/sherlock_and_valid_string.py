from collections import Counter

freqs = Counter(list(raw_input()))
s = set(freqs.values())

f = sorted(freqs.values())
if len(s) == 1:
    print 'YES'
elif len(s) > 2:
    print 'NO'
elif f[-1] - f[-2] == 1:
    print 'YES'
elif f[0] == 1 and f[1] != 1:
    print 'YES'
else:
    print 'NO'
