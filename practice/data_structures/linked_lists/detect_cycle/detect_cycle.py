"""
 Check if linked list has cycle
 head could be None as well for empty list
 Node is defined as
 
 class Node(object):
 
   def __init__(self, data=None, next_node=None):
       self.data = data
       self.next = next_node

 return 0 if no cycle else return 1
"""

def HasCycle(i_head):
    if not i_head:
        return 0
    
    slow = i_head
    fast = i_head.next
    while slow and fast and slow != fast:
        slow = slow.next
        if not fast.next:
            return 0
        fast = fast.next.next
    if slow and fast and slow == fast:
        return 1
    return 0

