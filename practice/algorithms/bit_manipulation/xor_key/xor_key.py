#!/usr/bin/env python

import bisect

class Node(object):
    def __init__(self):
        self._Left  = None
        self._Right = None
        self.Index = []
    
    def get_right(self):
        return self._Right
    
    def set_right(self, i_node):
        self._Right = i_node
    
    def get_left(self):
        return self._Left
    
    def set_left(self, i_node):
        self._Left = i_node
    
    def add_index(self, i_index):
        bisect.insort_right(self.Index, i_index)
    
    def has_index_in_range(self, i_min_index, i_max_index):
        min_pos = bisect.bisect_left(self.Index, i_min_index)
        max_pos = bisect.bisect_right(self.Index, i_max_index)
        return min_pos < max_pos
    
class Trie:
    def __init__(self, i_arr):
        self.Root = Node()
        self.NumBits = 15
        self.Mask = [1 << POS for POS in range(self.NumBits)]
        
        for POS in range(len(i_arr)):
            val = i_arr[POS]
            self.Root.add_index(POS)
            
            node = self.Root
            nb = self.NumBits - 1
            while nb >= 0:
                mask = self.Mask[nb]
                if val & self.Mask[nb] == 0:
                    if not node.get_left():
                        node.set_left(Node())
                    node = node.get_left()
                else:
                    if not node.get_right():
                        node.set_right(Node())
                    node = node.get_right()
                node.add_index(POS)
                nb -= 1
      
    def max_xor(self, i_value, i_min_index, i_max_index):
        if not self.Root.has_index_in_range(i_min_index, i_max_index):
            return 2 ** self.NumBits - 1
        
        res = 0
        node = self.Root
        nb = self.NumBits - 1
        while nb >= 0:
            mask = self.Mask[nb]
            if i_value & mask == 0:
                if node.get_right() and (not node.get_left() or node.get_right().has_index_in_range(i_min_index, i_max_index)):
                    res += mask
                    node = node.get_right()
                else:
                    node = node.get_left()
            elif node.get_left() and (not node.get_right() or node.get_left().has_index_in_range(i_min_index, i_max_index)):
                res += mask
                node = node.get_left()
            else:
                node = node.get_right()
            nb -= 1
        return res

t = int(raw_input().strip())
for _ in range(t):
    n, q = map(int, raw_input().strip().split())
    arr = map(int, raw_input().strip().split())
    trie = Trie(arr)
    for __ in xrange(q):
        a, p, q = map(int, raw_input().strip().split())
        print trie.max_xor(a, p - 1, q - 1)

