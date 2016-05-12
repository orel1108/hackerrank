"""
 Merge two linked lists
 head could be None as well for empty list
 Node is defined as
 
 class Node(object):
 
   def __init__(self, data=None, next_node=None):
       self.data = data
       self.next = next_node

 return back the head of the linked list in the below method.
"""

def MergeLists(i_headA, i_headB):
    if not i_headA:
        return i_headB
    if not i_headB:
        return i_headA
    
    head = Node()
    if i_headA.data < i_headB.data:
        head = i_headA
        i_headA = i_headA.next
    else:
        head = i_headB
        i_headB = i_headB.next
    
    cp = head
    while i_headA and i_headB:
        if i_headA.data < i_headB.data:
            head.next = i_headA
            i_headA = i_headA.next
        else:
            head.next = i_headB
            i_headB = i_headB.next
        head = head.next
    
    if not i_headA and i_headB:
        head.next = i_headB
    elif i_headA and not i_headB:
        head.next = i_headA
    return cp

