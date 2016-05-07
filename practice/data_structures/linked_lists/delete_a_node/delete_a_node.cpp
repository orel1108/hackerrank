/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

Node * Delete(Node * i_head, int i_position)
{
    if (i_position == 0)
    {
        i_head = i_head->next;
        return i_head;
    }
    
    Node * node = i_head;
    while (i_position > 1)
    {
        node = node->next;
        i_position--;
    }
    
    node->next = node->next->next;
    return i_head;
}

