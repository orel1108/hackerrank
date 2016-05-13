/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/


void postOrder(node * i_root)
{
    if (i_root) {
        postOrder(i_root->left);
        postOrder(i_root->right);
        cout << i_root->data << " ";
    }
}

