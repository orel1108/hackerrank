#!/usr/bin/env python

class Node(object):
    def __init__(self, i_data):
        self.Left = None
        self.Right = None
        self.Data = i_data

def search(i_root, i_data):
    q = [i_root]
    while q:
        top = q.pop(0)
        if top.Data == i_data:
            return top
        if top.Left:
            q.append(top.Left)
        if top.Right:
            q.append(top.Right)

def inorder(i_root):
    stack = []
    curr_node = i_root
    while True:
        if curr_node:
            stack.append(curr_node)
            curr_node = curr_node.Left
        elif stack:
            node = stack.pop()
            print node.Data,
            curr_node = node.Right
        if not curr_node and not stack:
            return

def swap(i_root, i_k, i_n):
    q = [i_root]
    depths = [0 for _ in range(i_n + 1)]
    depths[1] = 1
    while q:
        top = q.pop(0)
        d = depths[top.Data]
        if d % i_k == 0:
            top.Left, top.Right = top.Right, top.Left
        if top.Left:
            q.append(top.Left)
            depths[top.Left.Data] = d + 1
        if top.Right:
            q.append(top.Right)
            depths[top.Right.Data] = d + 1

root = None
n = int(raw_input().strip())
cnt = 1
for _ in xrange(n):
    a, b = map(int, raw_input().strip().split())
    if cnt == 1:
        root = Node(1)
        if a != -1:
            root.Left = Node(a)
        if b != -1:
            root.Right = Node(b)
    else:
        l = search(root, cnt)
        if a != -1:
            l.Left = Node(a)
        if b != -1:
            l.Right = Node(b)
    cnt += 1

t = int(raw_input().strip())
for _ in xrange(t):
    k = int(raw_input().strip())
    swap(root, k, n)
    inorder(root)   
    print

