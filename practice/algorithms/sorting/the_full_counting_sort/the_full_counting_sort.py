#!/usr/bin/env python

def stable_sort(i_arr):
    count = [0 for _ in range(100)]
    for x in i_arr:
        count[x[0]] += 1
    
    total = 0
    for i in range(100):   # i = 0, 1, ... k-1
        oldCount = count[i]
        count[i] = total
        total += oldCount
    
    res = [0 for _ in range(len(i_arr))]
    for x in i_arr:
        res[count[x[0]]] = x
        count[x[0]] += 1
 
    return res

n = int(raw_input().strip())
phrases = []
for i in range(n):
    row = raw_input().strip().split()
    if i < n // 2:
        phrases.append([int(row[0]),"-"])
    else:
        phrases.append([int(row[0]),str(row[1])])

sorted_phrases = stable_sort(phrases)
for item in sorted_phrases:
    print item[1],

