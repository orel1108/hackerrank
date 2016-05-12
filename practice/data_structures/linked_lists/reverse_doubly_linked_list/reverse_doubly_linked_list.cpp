/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/

Node * Reverse(Node * i_head)
{
    if (!i_head)
    {
        return i_head;
    }
    
    while (i_head->next)
    {
        Node * node = i_head->next;
        swap(i_head->prev, i_head->next);
        i_head = node;
    }
    swap(i_head->prev, i_head->next);
    
    return i_head;
}

