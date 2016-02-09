# Enter your code here. Read input from STDIN. Print output to STDOUT
from collections import defaultdict

t = int(raw_input())
for _ in range(t):
    s = raw_input()
    n = len(s)
    counter = defaultdict(int)
    for LEFT in range(n):
        for RIGHT in range(LEFT, n):
            ss = ''.join(sorted(s[LEFT:RIGHT + 1]))
            counter[ss] += 1
    r = 0
    for VAL in counter.values():
        r += VAL * (VAL - 1) // 2
    print r

