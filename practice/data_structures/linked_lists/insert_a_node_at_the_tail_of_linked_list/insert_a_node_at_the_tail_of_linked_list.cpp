/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

Node * Insert(Node * i_head, int i_data)
{
    if (!i_head)
    {
        Node * node = new Node;
        node->data = i_data;
        return node;
    }
    
    Node * node = i_head;
    while (node->next)
    {
        node = node->next;
    }
    
    Node * n = new Node;
    n->data = i_data;
    node->next = n;
    
    return i_head;
}

