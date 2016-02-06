from collections import Counter
string = raw_input()
counter = Counter(string)

k = 0
for VAL in counter.values():
    if VAL % 2 == 1:
        k += 1
if k > 1:
    print "NO"
else:
    print "YES"
