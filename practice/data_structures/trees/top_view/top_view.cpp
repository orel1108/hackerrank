/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void top_view(node * i_root)
{
    node * right = i_root->right;
    node * left = i_root->left;
    vector<int> d;
    while (left)
    {
        d.insert(d.begin(), left->data);
        left = left->left;
    }
    
    d.push_back(i_root->data);
    while (right)
    {
        d.push_back(right->data);
        right = right->right;
    }
    
    for (int pos = 0; pos < d.size(); ++pos)
    {
        cout << d[pos] << " ";
    }
}

