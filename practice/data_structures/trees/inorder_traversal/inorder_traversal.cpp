/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/

void inOrder(node * i_root)
{
    if (i_root)
    {
        inOrder(i_root->left);
        cout << i_root->data << " ";
        inOrder(i_root->right);
    }
}

