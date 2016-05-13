/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

int height(node * i_node)
{
    if (!i_node)
    {
        return -1;
    }
        
    return i_node->ht;
}

int balance_factor(node * i_node)
{
    return height(i_node->left) - height(i_node->right);
}

void over_height(node * i_node)
{
    int left_height = height(i_node->left);
    int right_height = height(i_node->right);
    if (left_height > right_height)
    {
        i_node->ht = left_height + 1;   
    }
    else
    {
        i_node->ht = right_height + 1;
    }
}

node * right_rotation(node * i_node)
{
    node * tmp = i_node->left;
    i_node->left = tmp->right;
    tmp->right = i_node;
    over_height(i_node);
    over_height(tmp);
    return tmp;
}

node * left_rotation(node * i_node)
{
    node * tmp = i_node->right;
    i_node->right = tmp->left;
    tmp->left = i_node;
    over_height(i_node);
    over_height(tmp);
    return tmp;
}

node * balance(node * i_node)
{
    over_height(i_node);
    if (balance_factor(i_node) == -2)
    {
        if (balance_factor(i_node->right) > 0)
        {
            i_node->right = right_rotation(i_node->right);
        }
        return left_rotation(i_node);
    }
    if (balance_factor(i_node) == 2)
    {
        if (balance_factor(i_node->left) < 0)
        {
            i_node->left = left_rotation(i_node->left);
        }
        return right_rotation(i_node);
    }
    return i_node;
}

node * insert(node * i_root, int i_val)
{
    if (!i_root)
    {
        i_root = new node();
        i_root->val = i_val;
        i_root->ht = 0;
        return i_root;
    }
    if (i_root->val < i_val)
    {
        i_root->right = insert(i_root->right, i_val);
    }
    else
    {
        i_root->left = insert(i_root->left, i_val);
    }
    return balance(i_root);
}

