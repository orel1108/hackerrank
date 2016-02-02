t = int(raw_input())
for _ in range(t):
    s = raw_input()
    cnt = 0
    for POS in range(len(s) // 2):
        cnt += abs(ord(s[POS]) - ord(s[len(s) - POS - 1]))
    print cnt
