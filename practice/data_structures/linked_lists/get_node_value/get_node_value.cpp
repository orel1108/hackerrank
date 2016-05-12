/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

int GetNode(Node * i_head, int i_positionFromTail)
{
    Node *head1 = i_head, *head2 = i_head;
    
    int cnt = 0;
    while (head1 && (cnt < i_positionFromTail))
    {
        cnt++;
        head1 = head1->next;
    }
    
    if (cnt != i_positionFromTail)
    {
        //error
        return -1;
    }
    
    while (head1->next)
    {
        head1 = head1->next;
        head2 = head2->next;
    }
    
    return head2->data;
}

