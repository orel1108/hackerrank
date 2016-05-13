
/*The tree node has data, left child and right child 
struct node
{
    int data;
    node* left;
    node* right;
};

*/

int height(node * i_root)
{
    if (i_root)
    {
        if (!i_root->left && !i_root->right)
        {
            return 0;
        }
        return max(height(i_root->left), height(i_root->right)) + 1;
    }
    return 0;
}

