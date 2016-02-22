#!/usr/bin/env python

ID, SUBJ_NUM = map(int, raw_input().strip().split())
marks = []
for _ in range(SUBJ_NUM):
    m = map(float, raw_input().strip().split())
    marks.append(m)

for COL in zip(*marks):
    print sum(COL) / SUBJ_NUM

