# Enter your code here. Read input from STDIN. Print output to STDOUT
from collections import Counter

s = list(reversed(raw_input()))
n = len(s)
h = n // 2
sf = Counter(s)
af = Counter()
for KEY in sf.keys():
    af[KEY] = sf[KEY] // 2

a = []
pos = 0
while len(a) < h:
    min_char_at = -1
    while True:
        c = s[pos]
        if af[c] > 0 and (min_char_at < 0 or c < s[min_char_at]):
            min_char_at = pos
        sf[c] -= 1
        if sf[c] < af[c]:
            break
        pos += 1
    for POS in range(min_char_at + 1, pos + 1):
        sf[s[POS]] += 1
    af[s[min_char_at]] -= 1
    a.append(s[min_char_at])
    pos = min_char_at + 1
print ''.join(a)

