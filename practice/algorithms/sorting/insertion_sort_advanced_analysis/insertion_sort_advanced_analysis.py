#!/usr/bin/python

INF = 10000000
answer = 0

def merge(i_left_part, i_right_part):
    global answer
    
    res_left = [ITEM for ITEM in i_left_part]
    res_left.append(INF)
    
    res_right = [ITEM for ITEM in i_right_part]
    res_right.append(INF)
    
    res = []
    k = 0
    l = 0
    for _ in range(len(i_left_part) + len(i_right_part)):
        if res_left[k] <= res_right[l]:
            res.append(res_left[k])
            k += 1
        else:
            res.append(res_right[l])
            l += 1
            answer += (len(i_left_part) - k)
    return res

def adv_sort(i_array):
    if len(i_array) < 2:
        return i_array

    mid = len(i_array) / 2
    
    left_part = adv_sort(i_array[:mid])
    right_part = adv_sort(i_array[mid:])
    
    res = merge(left_part, right_part)
    return res

n = int(raw_input().strip())
for _ in range(n):
    x = int(raw_input().strip())
    a = map(int, raw_input().strip().split())
    
    answer = 0
    adv_sort(a)
    
    print answer

