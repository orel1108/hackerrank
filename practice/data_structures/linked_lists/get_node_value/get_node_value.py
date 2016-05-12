"""
 Get Node data of the Nth Node from the end.
 head could be None as well for empty list
 Node is defined as
 
 class Node(object):
 
   def __init__(self, data=None, next_node=None):
       self.data = data
       self.next = next_node

 return back the node data of the linked list in the below method.
"""

def GetNode(i_head, i_position):
    head1 = i_head
    head2 = i_head
    
    cnt = 0
    while head1 and cnt < i_position:
        head1 = head1.next;
        cnt += 1
        
    while head1.next:
        head1 = head1.next
        head2 = head2.next
        
    return head2.data

