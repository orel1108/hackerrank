"""
 Insert Node at the end of a linked list
 head input could be None as well for empty list
 Node is defined as
 
 class Node(object):
 
   def __init__(self, data=None, next_node=None):
       self.data = data
       self.next = next_node

 return back the head of the linked list in the below method. 
"""

def InsertNth(i_head, i_data, i_position):
    if i_position == 0:
        return Node(i_data, i_head)
    cp = i_head
    while i_position > 1:
        cp = cp.next
        i_position -= 1
    n = Node(i_data, cp.next)
    cp.next = n
    return i_head

