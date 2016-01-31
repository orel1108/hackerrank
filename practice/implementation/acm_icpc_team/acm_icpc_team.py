#!/bin/python

import sys

n, m = map(int, raw_input().strip().split())
topic = []
for _ in range(n):
    row = str(raw_input().strip())
    topic.append(row)

mx = 0
cnt = 0

def num_topics(i_team_1, i_team_2):
    cnt = 0
    for CNT in range(len(i_team_1)):
        if i_team_1[CNT] == '1' or i_team_2[CNT] == '1':
            cnt += 1
    return cnt

for CNT1 in range(n):
    for CNT2 in range(CNT1 + 1, n):
        num = num_topics(topic[CNT1], topic[CNT2])
        if num > mx:
            mx = num
            cnt = 1
        elif num == mx:
            cnt += 1

print mx
print cnt
