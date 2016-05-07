/*
  Insert Node at the begining of a linked list
  Initially head pointer argument could be NULL for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
return back the pointer to the head of the linked list in the below method.
*/

Node * Insert(Node * i_head, int i_data)
{
    Node * node = new Node;
    node->data = i_data;
    node->next = i_head;
    return node;
}

