"""
 Compare two linked list
 head could be None as well for empty list
 Node is defined as
 
 class Node(object):
 
   def __init__(self, data=None, next_node=None):
       self.data = data
       self.next = next_node

 return back the head of the linked list in the below method.
"""

def CompareLists(i_headA, i_headB):
    if not i_headA:
        if not i_headB:
            return 1
        else:
            return 0
    if not i_headB:
        return 0
    
    while i_headA and i_headB:
        if i_headA.data != i_headB.data:
            return 0
        i_headA = i_headA.next
        i_headB = i_headB.next
    if not i_headA and not i_headB:
        return 1
    return 0

