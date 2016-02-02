def is_kaprekar(i_n):
    d = len(str(i_n))
    s = i_n ** 2
    r = s % 10 ** d
    l = s // 10 ** d
    return r + l == i_n

p = int(raw_input())
q = int(raw_input())

res = []
for VAL in range(p, q + 1):
    if is_kaprekar(VAL):
        res.append(VAL)
if res:
    for VAL in res:
        print VAL, 
else:
    print 'INVALID RANGE'
