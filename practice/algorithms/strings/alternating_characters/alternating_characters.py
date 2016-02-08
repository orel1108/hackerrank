t = int(raw_input())
for _ in range(t):
    s = raw_input()
    last = ''
    cnt = 0
    for CHR in s:
        if CHR != last:
            last = CHR
            cnt += 1
    print len(s) - cnt
