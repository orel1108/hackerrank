import math

t = int(raw_input())
for _ in range(t):
    a, b = map(int, raw_input().split())
    ra = math.sqrt(a)
    rb = math.sqrt(b)
    ia = int(ra)
    ib = int(rb)
    
    if ia < ra:
        ia += 1
    print ib - ia + 1
