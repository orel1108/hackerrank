/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

Node * InsertNth(Node * i_head, int i_data, int i_position)
{
    Node * node = new Node;
    node->data = i_data;
    
    if (i_position == 0)
    {
        node->next = i_head;
        return node;
    }
    
    Node * head = i_head;
    while (i_position > 1)
    {
        head = head->next;
        i_position--;
    }
    
    node->next = head->next;
    head->next = node;
    
    return i_head;
}

