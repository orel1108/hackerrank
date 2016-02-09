#!/usr/bin/env python

recs = []
n = input()
for _ in range(n):
    rec = raw_input().rstrip().split(' ')
    record = {}
    record['name'] = rec[0]
    record['math'] = rec[1]
    record['phys'] = rec[2]
    record['chem'] = rec[3]
    recs.append(record)

inpname = raw_input().strip()
for item in recs:
    if item['name'] == str(inpname):
        sum = float(item['math']) + float(item['phys']) + float(item['chem'])
        print '%.2f' % (sum/3.0)
