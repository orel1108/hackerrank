s1 = raw_input().strip()
s2 = raw_input().strip()

n = len(s1)

prev = [0 for _ in range(n + 1)]
curr = [0 for _ in range(n + 1)]
for ROW_NUM in range(1, n + 1):
    for COL_NUM in range(1, n + 1):
        if s1[ROW_NUM - 1] != s2[COL_NUM - 1]:
            curr[COL_NUM] = max(curr[COL_NUM - 1], prev[COL_NUM])
        else:
            curr[COL_NUM] = prev[COL_NUM - 1] + 1
    prev = list(curr)
print prev[-1]
