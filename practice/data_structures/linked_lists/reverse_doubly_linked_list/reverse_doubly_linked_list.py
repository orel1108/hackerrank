"""
 Reverse a doubly linked list
 head could be None as well for empty list
 Node is defined as
 
 class Node(object):
 
   def __init__(self, data=None, next_node=None, prev_node = None):
       self.data = data
       self.next = next_node
       self.prev = prev_node

 return the head node of the updated list 
"""

def Reverse(i_head):
    if not i_head:
        return i_head
    while i_head.next:
        cp = i_head.next
        i_head.prev, i_head.next = i_head.next, i_head.prev
        i_head = cp
    i_head.prev, i_head.next = i_head.next, i_head.prev
    return i_head

