#!/usr/bin/env python

from collections import namedtuple

n = int(raw_input().strip())
s = raw_input().strip()
Student = namedtuple('Student', s)

students = []
for _ in range(n):
    m = raw_input().strip().split()
    students.append(Student(m[0], m[1], m[2], m[3]))
    
total = 0.0
for STUDENT in students:
    total += float(STUDENT.MARKS)
print total / n

