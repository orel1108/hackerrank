/*
  Print elements of a linked list in reverse order as standard output
  head pointer could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

void ReversePrint(Node * i_head)
{
    if (i_head)
    {
        ReversePrint(i_head->next);
        cout << i_head->data << endl;
    }
}

