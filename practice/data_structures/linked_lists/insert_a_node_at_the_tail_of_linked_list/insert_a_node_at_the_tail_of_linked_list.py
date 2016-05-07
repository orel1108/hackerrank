"""
 Insert Node at the end of a linked list 
 head pointer input could be None as well for empty list
 Node is defined as
 
 class Node(object):
 
   def __init__(self, data=None, next_node=None):
       self.data = data
       self.next = next_node
 
 return back the head of the linked list in the below method
"""

def Insert(i_head, i_data):
    if not i_head:
        return Node(i_data)
    cp = i_head
    while cp.next:
        cp = cp.next
    n = Node(i_data)
    cp.next = n
    return i_head

