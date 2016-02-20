#!/usr/bin/env python

from collections import Counter, OrderedDict

freqs = Counter(raw_input().strip()).most_common()[:3]

for cnt in range(2):
    if freqs[cnt][1] == freqs[cnt + 1][1]:
        if ord(freqs[cnt][0]) > ord(freqs[cnt + 1][0]):
            freqs[cnt], freqs[cnt + 1] = freqs[cnt + 1], freqs[cnt]

if freqs[0][1] == freqs[1][1]:
    if ord(freqs[0][0]) > ord(freqs[1][0]):
        freqs[0], freqs[1] = freqs[1], freqs[0]

for PAIR in freqs:
    print PAIR[0], PAIR[1]

