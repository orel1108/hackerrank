/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

Node * RemoveDuplicates(Node * i_head)
{
    if (!i_head)
    {
        return i_head;
    }
    
    Node * cp = i_head;
    while (i_head)
    {
        if (i_head->next && (i_head->data == i_head->next->data))
        {
            Node * node = i_head->next;
            while (node && (i_head->data == node->data))
            {
                node = node->next;
            }
            i_head->next = node;
        }
        i_head = i_head->next;
    }
    
    return cp;
}

