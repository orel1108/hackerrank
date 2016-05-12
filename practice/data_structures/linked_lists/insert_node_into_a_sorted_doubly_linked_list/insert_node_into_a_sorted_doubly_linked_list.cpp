/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/

Node * SortedInsert(Node * i_head, int i_data)
{
    if (!i_head)
    {
        Node * head = new Node;
        head->prev = head->next = nullptr;
        head->data = i_data;
        return head;
    }
    
    if (i_head->data > i_data)
    {
        Node * head = new Node;
        head->prev = nullptr;
        head->next = i_head;
        head->data = i_data;
        
        i_head->prev = head;
        return head;
    }
    
    Node * node = i_head;
    while (node->next && (node->data < i_data))
    {
        node = node->next;
    }
    if (!node->next && (node->data < i_data))
    {
        Node * last = new Node;
        last->data = i_data;
        last->next = nullptr;
        last->prev = node;
        node->next = last;
    }
    else
    {
        Node * last = new Node;
        last->data = i_data;
        last->next = node;
        last->prev = node->prev;
        
        last->prev->next = last;
        node->prev = last;
    }
    
    return i_head;
}

