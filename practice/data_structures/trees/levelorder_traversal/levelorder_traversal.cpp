
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

void LevelOrder(node * i_root)
{
    vector<node*> q;
    q.push_back(i_root);
    int cnt = 0;
    while (cnt < q.size())
    {
        cout << q[cnt]->data << " ";
        if (q[cnt]->left)
        {
            q.push_back(q[cnt]->left);
        }
        if (q[cnt]->right)
        {
            q.push_back(q[cnt]->right);
        }
        cnt++;
    }
}

