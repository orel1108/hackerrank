"""
 Reverse a linked list
 head could be None as well for empty list
 Node is defined as
 
 class Node(object):
 
   def __init__(self, data=None, next_node=None):
       self.data = data
       self.next = next_node

 return back the head of the linked list in the below method.
"""

def Reverse(i_head):
    if not i_head:
        return i_head
    prev = None
    curr = i_head
    next = curr.next
    while next:
        curr.next = prev
        prev = curr
        curr = next
        next = curr.next
    curr.next = prev
    return curr

