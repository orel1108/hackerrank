/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/


void decode_huff(node * i_root, const string & i_s)
{
    int pos = 0;
    node * n;
    while (pos < i_s.size()) {
        n = i_root;
        while (n->left or n->right)
        {
            if (i_s[pos] == '0')
            {
                n = n->left;
            }
            else
            {
                n = n->right;
            }
            pos++;
        }
        cout << n->data;
    }
}

