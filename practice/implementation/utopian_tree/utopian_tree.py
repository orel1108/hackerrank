#!/bin/python

def getHeight(ncycles):
    if ncycles == 0:
        return 1
    return 2 * getHeight(ncycles - 1) if ncycles % 2 == 1 else 1 + getHeight(ncycles - 1)

t = int(raw_input().strip())
for _ in range(t):
    n = int(raw_input().strip())
    print getHeight(n)
