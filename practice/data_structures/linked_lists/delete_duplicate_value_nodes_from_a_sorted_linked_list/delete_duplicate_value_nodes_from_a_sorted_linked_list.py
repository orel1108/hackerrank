"""
 Delete duplicate nodes
 head could be None as well for empty list
 Node is defined as
 
 class Node(object):
 
   def __init__(self, data=None, next_node=None):
       self.data = data
       self.next = next_node

 return back the head of the linked list in the below method.
"""

def RemoveDuplicates(i_head):
    if not i_head:
        return i_head
    cp = i_head
    while i_head:
        if i_head.next and i_head.data == i_head.next.data:
            hn = i_head.next
            while hn and i_head.data == hn.data:
                hn = hn.next
            i_head.next = hn
        i_head = i_head.next
    return cp

