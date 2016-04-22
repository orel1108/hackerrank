#!/usr/bin/env python

def count_ch(i_adj_list, i_par):
    cnt = len(i_adj_list[i_par])
    if cnt > 0:
        for VAL in i_adj_list[i_par]:
            cnt += count_ch(i_adj_list, VAL)
    return cnt

n, m = map(int, raw_input().strip().split())
adj_list = [set() for _ in range(n + 1)]
for _ in range(m):
    v1, v2 = map(int, raw_input().strip().split())
    adj_list[v2].add(v1)

num_ch = [0 for _ in range(n + 1)]
for POS in range(1, n + 1):
    num_ch[POS] = count_ch(adj_list, POS)
    
num_ch = sorted(num_ch)

num_edge = 0
for POS in range(n):
    if num_ch[POS] % 2 == 1:
        num_edge += 1
print num_edge

