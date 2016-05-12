/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/

int FindMergeNode(Node * i_headA, Node * i_headB)
{
    while (i_headA)
    {
        Node * node = i_headB;
        while (node)
        {
            if (i_headA == node)
            {
                return i_headA->data;
            }
            node = node->next;
        }
        i_headA = i_headA->next;
    }
    
    return -1;
}

