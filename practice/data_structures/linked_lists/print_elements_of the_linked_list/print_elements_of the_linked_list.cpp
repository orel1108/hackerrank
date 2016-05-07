/*
  Print elements of a linked list on console 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

void Print(Node * i_head)
{
    if (i_head)
    {
        cout << i_head->data << endl;
        Print(i_head->next);
    }
}

