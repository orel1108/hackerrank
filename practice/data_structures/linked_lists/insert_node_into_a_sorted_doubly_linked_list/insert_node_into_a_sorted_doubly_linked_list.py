"""
 Insert a node into a sorted doubly linked list
 head could be None as well for empty list
 Node is defined as
 
 class Node(object):
 
   def __init__(self, data=None, next_node=None, prev_node = None):
       self.data = data
       self.next = next_node
       self.prev = prev_node

 return the head node of the updated list 
"""

def SortedInsert(i_head, i_data):
    if not i_head:
        return Node(i_data)
    if i_head.data > i_data:
        n = Node(i_data, i_head)
        i_head.prev = n
        i_head = n
        return i_head
    
    cp = i_head
    while cp.next and cp.data < i_data:
        cp = cp.next
    if not cp.next and cp.data < i_data:
        n = Node(i_data, None, cp)
        cp.next = n
    else:
        n = Node(i_data, cp, cp.prev)
        cp.prev.next = n
        cp.prev = n
    return i_head

