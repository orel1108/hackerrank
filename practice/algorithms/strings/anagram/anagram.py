from collections import Counter

t = int(raw_input())
for _ in range(t):
    s = raw_input()
    if len(s) % 2 == 1:
        print -1
    else:
        c1 = Counter(s[:len(s) // 2])
        c2 = Counter(s[len(s) // 2:])
        for KEY in c1.keys():
            if KEY in c2.keys():
                c1[KEY] -= c2[KEY]
        s_pos = 0
        s_neg = 0
        for VAL in c1.values():
            if VAL < 0:
                s_neg += VAL
            else:
                s_pos += VAL
        print max(s_pos, abs(s_neg))
