/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

Node * MergeLists(Node * i_headA, Node * i_headB)
{
    if (!i_headA)
    {
        return i_headB;
    }
    if (!i_headB)
    {
        return i_headA;
    }
    
    Node * head;
    if (i_headA->data < i_headB->data)
    {
        head = i_headA;
        i_headA = i_headA->next;
    }
    else
    {
        head = i_headB;
        i_headB = i_headB->next;
    }
    
    Node * cp = head;
    while (i_headA && i_headB)
    {
        if (i_headA->data < i_headB->data)
        {
            head->next = i_headA;
            i_headA = i_headA->next;
        }
        else
        {
            head->next = i_headB;
            i_headB = i_headB->next;
        }
        head = head->next;
    }
    
    if (!i_headA && i_headB)
    {
        head->next = i_headB;
    }
    else if (i_headA && !i_headB)
    {
        head->next = i_headA;
    }
    
    return cp;
}

