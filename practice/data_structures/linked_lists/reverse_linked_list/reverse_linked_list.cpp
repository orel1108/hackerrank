/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

Node * Reverse(Node * i_head)
{
    if (!i_head)
    {
        return i_head;
    }
    
    Node *prev = nullptr, *curr = i_head, *next = curr->next;
    while (next)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr->next;
    }
    curr->next = prev;
    
    return curr;
}

