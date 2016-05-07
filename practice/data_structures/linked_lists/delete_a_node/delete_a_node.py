"""
 Delete Node at a given position in a linked list
 Node is defined as
 
 class Node(object):
 
   def __init__(self, data=None, next_node=None):
       self.data = data
       self.next = next_node

 return back the head of the linked list in the below method. 
"""

def Delete(i_head, i_position):
    if i_position == 0:
        i_head = i_head.next
        return i_head
    cp = i_head
    while i_position > 1:
        cp = cp.next
        i_position -= 1
    cp.next = cp.next.next
    return i_head

