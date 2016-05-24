#!/usr/bin/env python

class Heap(object):
    def __init__(self):
        self.__Pos = dict()
        self.__Data = [0 for _ in range(100000)]
        self.__Size = 0
        
    def insert(self, i_val):
        self.__Size += 1
        self.__Data[self.__Size] = i_val
        self.__Pos[i_val] = self.__Size
        
        pos = self.__Size
        while pos > 1:
            if self.__Data[pos] < self.__Data[pos // 2]:
                self.__Pos[self.__Data[pos]] = pos // 2
                self.__Pos[self.__Data[pos // 2]] = pos
                self.__Data[pos], self.__Data[pos // 2] = self.__Data[pos // 2], self.__Data[pos]
                pos //= 2
            else:
                break
    
    def remove(self, i_val):
        idx = self.__Pos[i_val]
        self.__Pos[i_val] = 0
        self.__Pos[self.__Data[self.__Size]] = idx
        self.__Data[idx] = self.__Data[self.__Size]
        self.__Size -= 1
        
        while True:
            l, r = 2 * idx, 2 * idx + 1
            if l <= self.__Size:
                if r < self.__Size:
                    if self.__Data[idx] > self.__Data[l] or self.__Data[idx] > self.__Data[r]:
                        sidx = l if self.__Data[l] < self.__Data[r] else r
                        self.__Pos[self.__Data[sidx]] = idx
                        self.__Pos[self.__Data[idx]] = sidx
                        self.__Data[idx], self.__Data[sidx] = self.__Data[sidx], self.__Data[idx]
                        idx = sidx
                    else:
                        break
                else:
                    if self.__Data[idx] > self.__Data[l]:
                        self.__Pos[self.__Data[l]] = idx
                        self.__Pos[self.__Data[idx]] = l
                        self.__Data[idx], self.__Data[l] = self.__Data[l], self.__Data[idx]
                        idx = l
                    else:
                        break
            else:
                break
    
    def min_val(self):
        return self.__Data[1]


q = int(raw_input().strip())
heap = Heap()
for _ in xrange(q):
    i = map(int, raw_input().strip().split())
    if i[0] == 1:
        heap.insert(i[1])
    elif i[0] == 2:
        heap.remove(i[1])
    else:
        print heap.min_val()

