#!/usr/bin/env python

n = int(raw_input().strip())
a = []
for _ in range(n):
    comm = raw_input().split()
    if comm[0] == "append":
        a.append(int(comm[1]))
    elif comm[0] == "insert":
        a.insert(int(comm[1]), int(comm[2]))
    elif comm[0] == "remove":
        a.remove(int(comm[1]))
    elif comm[0] == "pop":
        a.pop()
    elif comm[0] == "index":
        a.index(int(comm[1]))
    elif comm[0] == "count":
        a.count(int(comm[1]))
    elif comm[0] == "sort":
        a.sort()
    elif comm[0] == "reverse":
        a.reverse()
    elif comm[0] == "print":
        print a
