t = int(raw_input())
def is_palindrom(i_s):
    CNT = 0
    while CNT < len(i_s) // 2 and i_s[CNT] == i_s[len(i_s) - CNT - 1]:
        CNT += 1
    if CNT == (len(i_s) // 2):
        return True
    return False

for _ in range(t):
    s = raw_input()
    cnt = 0
    while cnt < len(s) // 2 and s[cnt] == s[len(s) - cnt - 1]:
        cnt += 1
    if cnt == len(s) // 2:
        print -1
    else:
        if is_palindrom(s[:cnt] + s[cnt + 1:]):
            print cnt
        else:
            print len(s) - cnt - 1
