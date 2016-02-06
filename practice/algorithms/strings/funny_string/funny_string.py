def is_funny(i_str):
    s = len(i_str)
    for CNT in range(s - 1):
        if abs(ord(i_str[CNT + 1]) - ord(i_str[CNT])) != abs(ord(i_str[s - 1 - CNT]) - ord(i_str[s - 2 - CNT])):
            return "Not Funny"
    return "Funny"
t = int(raw_input())
for _ in range(t):
    s = raw_input()
    print is_funny(s)
