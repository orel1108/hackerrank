"""
 Find the node at which both lists merge and return the data of that node.
 head could be None as well for empty list
 Node is defined as
 
 class Node(object):
 
   def __init__(self, data=None, next_node=None):
       self.data = data
       self.next = next_node

 
"""

def FindMergeNode(i_headA, i_headB):
    while i_headA:
        cp = i_headB
        while cp:
            if i_headA == cp:
                return i_headA.data
            cp = cp.next
        i_headA = i_headA.next

