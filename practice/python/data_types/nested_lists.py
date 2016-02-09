#!/usr/bin/env python

n = int(raw_input().strip())
ls = ['', 0]
students = []
for _ in range(n):
    name = raw_input().strip()
    mark = float(raw_input().strip())
    students.append([name, mark])

marks = [students[i][1] for i in range(n)]
m = min(marks)
for i in range(n):
    if marks[i] == m:
        marks[i] = 100
m = min(marks)

names = []
for i in range(n):
    if students[i][1] == m:
        names.append(students[i][0])

names.sort()
for NAME in names:
    print NAME
