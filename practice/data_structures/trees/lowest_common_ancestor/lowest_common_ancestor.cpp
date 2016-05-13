/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/


node * lca(node * i_root, int i_v1, int i_v2)
{
    if (i_v1 > i_v2)
    {
        swap(i_v1, i_v2);
    }
    if (i_root->data > i_v1 && i_root->data > i_v2)
    {
        return lca(i_root->left, i_v1, i_v2);
    }
    if (i_root->data < i_v1 && i_root->data < i_v2)
    {
        return lca(i_root->right, i_v1, i_v2);
    }
    return i_root;
}

