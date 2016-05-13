/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/

void preOrder(node * i_root)
{
    if (i_root)
    {
        cout << i_root->data << " ";
        preOrder(i_root->left);
        preOrder(i_root->right);        
    }
}

