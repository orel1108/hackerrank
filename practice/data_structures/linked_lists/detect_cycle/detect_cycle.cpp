/*
  Detect loop in a linked list 
  List could be empty also
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

int HasCycle(Node * i_head)
{
    if (!i_head)
    {
        return 0;
    }
    
    Node * slow = i_head;
    Node * fast = i_head->next;
    while (slow && fast && (slow != fast))
    {
        slow = slow->next;
        if (!fast->next)
        {
            return 0;
        }
        fast = fast->next->next;
    }
    if (slow && fast && (slow == fast))
    {
        return 1;
    }
    
    return 0;
}

