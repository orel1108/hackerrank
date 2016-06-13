#!/usr/bin/env python

from collections import Counter

d8_1 = [0, 8]
d8_2 = [16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 69, 27, 46, 65, 84, 23, 42, 61]


def is_subdict(i_dict_1, i_dict_2):
    for KEY in i_dict_1.keys():
        if KEY not in i_dict_2.keys():
            return False
        elif i_dict_2[KEY] < i_dict_1[KEY]:
            return False
    return True

div_8 = [8 * VAL for VAL in range(13, 125)]
div_8_ch = []
for VAL in div_8:
    div_8_ch.append(Counter(str(VAL)))

t = int(raw_input().strip())
for _ in xrange(t):
    v = str(raw_input().strip())
    if len(v) == 1:
        if int(v) in d8_1:
            print "YES"
        else:
            print "NO"
    elif len(v) == 2:
        if int(v) in d8_2:
            print "YES"
        else:
            print "NO"
    else:
        ch = Counter(v)
        e = False
        for VAL in div_8_ch:
            if is_subdict(VAL, ch):
                e = True
                break
        if e:
            print "YES"
        else:
            print "NO"

