#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

struct Node
{
    Node(int i_data)
        : left(nullptr)
        , right(nullptr)
        , data(i_data)
    {}
    
    Node * left;
    Node * right;
    int data;
};

Node * search(Node * i_root, int i_data)
{
    queue<Node*> q;
    q.push(i_root);
    
    while (!q.empty())
    {
        Node * top = q.front();
        q.pop();
        
        if (top->data == i_data)
        {
            return top;
        }
        if (top->left)
        {
            q.push(top->left);
        }
        if (top->right)
        {
            q.push(top->right);
        }
    }
    
    return nullptr;
}

void inorder(Node * i_root)
{
    stack<Node *> st;
    Node * curr = i_root;
    
    while (true)
    {
        if (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else if (!st.empty())
        {
            Node * node = st.top();
            st.pop();
            cout << node->data << " ";
            curr = node->right;
        }
        if (!curr && st.empty())
        {
            return;
        }
    }
}

void swap(Node * i_root, int i_k, int i_n)
{
    queue<Node *> q;
    q.push(i_root);
    
    vector<int> depths(i_n + 1);
    depths[1] = 1;
    while (!q.empty())
    {
        Node * top = q.front();
        q.pop();
        
        int d = depths[top->data];
        if ((d % i_k) == 0)
        {
            swap(top->left, top->right);
        }
        if (top->left)
        {
            q.push(top->left);
            depths[top->left->data] = d + 1;
        }
        if (top->right)
        {
            q.push(top->right);
            depths[top->right->data] = d + 1;
        }
    }
}

int main()
{
    int n, a, b, t, k;
    cin >> n;
    
    int cnt = 1;
    Node * root;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        if (cnt == 1)
        {
            root = new Node(1);
            if (a != -1)
            {
                root->left = new Node(a);
            }
            if (b != -1)
            {
                root->right = new Node(b);
            }
        }
        else
        {
            Node * node = search(root, cnt);
            if (a != -1)
            {
                node->left = new Node(a);
            }
            if (b != -1)
            {
                node->right = new Node(b);
            }
        }
        cnt++;
    }
    
    cin >> t;
    while (t--)
    {
        cin >> k;
        swap(root, k, n);
        inorder(root);
        cout << endl;
    }
    
    return 0;
}

