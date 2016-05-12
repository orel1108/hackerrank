/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

int CompareLists(Node * i_headA, Node * i_headB)
{
    if (!i_headA)
    {
        if (!i_headB)
        {
            return 1;
        }
        return 0;
    }
    
    if (!i_headB)
    {
        return 0;
    }
    
    while (i_headA && i_headB)
    {
        if (i_headA->data != i_headB->data)
        {
            return 0;
        }
        i_headA = i_headA->next;
        i_headB = i_headB->next;
    }
    
    if (!i_headA && !i_headB)
    {
        return 1;
    }
    
    return 0;
}

