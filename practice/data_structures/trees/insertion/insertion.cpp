/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/


node * insert(node * i_root, int i_value)
{
    if (!i_root) {
        node * n = new node();
        n->data = i_value;
        return n;
    }
    if (i_root->data < i_value) {
        if (!i_root->right) {
            node * n = new node();
            n->data = i_value;
            i_root->right = n;
        }
        else {
            insert(i_root->right, i_value);    
        }
    }
    else {
        if (!i_root->left) {
            node * n = new node();
            n->data = i_value;
            i_root->left = n;
        }
        else {
            insert(i_root->left, i_value);    
        }
    }
    return i_root;
}

