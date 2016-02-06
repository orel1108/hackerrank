from collections import Counter
import string

line_1 = str(raw_input())
line_2 = str(raw_input())

count_1 = Counter(line_1)
count_2 = Counter(line_2)

res = 0
for CHR in string.ascii_lowercase:
    if CHR in count_1.keys() and CHR in count_2.keys():
        res += abs(count_1[CHR] - count_2[CHR])
    elif CHR in count_1.keys():
        res += count_1[CHR]
    elif CHR in count_2.keys():
        res += count_2[CHR]
    
print res
