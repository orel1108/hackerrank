#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    Node()
        : left(nullptr)
        , right(nullptr)
    {}
    
    void add_index(int i_idx) { index.insert(
        upper_bound(index.begin(), index.end(), i_idx), i_idx); };
    
    bool has_index_in_range(int i_min_index, int i_max_index)
    {
        int min_pos = distance(index.begin(), 
                               lower_bound(index.begin(), index.end(), i_min_index));
        int max_pos = distance(index.begin(), 
                               upper_bound(index.begin(), index.end(), i_max_index));
        return min_pos < max_pos;
    }

    Node * left;
    Node * right;
    vector<int> index;
};

class Trie
{
public:
    Trie(const vector<int> & i_arr)
        : m_root(new Node())
        , m_num_bits(15)
        , m_mask(vector<int>(15))
    {
        for (int pos = 0; pos < m_num_bits; ++pos)
        {
            m_mask[pos] = 1 << pos;
        }
            
        for (int pos = 0; pos < i_arr.size(); ++pos)
        {
            int val = i_arr[pos];
            m_root->add_index(pos);
            
            Node * node = m_root;
            int nb = m_num_bits - 1;
            while (nb >= 0)
            {
                int mask = m_mask[nb];
                if ((val & mask) == 0)
                {
                    if (node->left == nullptr)
                    {
                        node->left = new Node();
                    }
                    node = node->left;
                }
                else
                {
                    if (node->right == nullptr)
                    {
                        node->right = new Node();
                    }
                    node = node->right;
                }
                node->add_index(pos);
                nb--;
            }
        }
    }
    
    int max_xor(int i_value, int i_min_index, int i_max_index) const
    {
        if (!m_root->has_index_in_range(i_min_index, i_max_index))
        {
            return 1 << m_num_bits - 1;
        }
        
        int res = 0;
        Node * node = m_root;
        int nb = m_num_bits - 1;
        while (nb >= 0)
        {
            int mask = m_mask[nb];
            if ((i_value & mask) == 0)
            {
                if (node->right != nullptr && 
                    (node->left == nullptr || (node->right)->has_index_in_range(i_min_index, i_max_index)))
                {
                    res += mask;
                    node = node->right;
                }
                else
                {
                    node = node->left;
                }
            }
            else if (node->left != nullptr && 
                     (node->right == nullptr || (node->left)->has_index_in_range(i_min_index, i_max_index)))
            {
                res += mask;
                node = node->left;
            }
            else
            {
                node = node->right;
            }
            nb--;
        }
        
        return res;
    }
    
private:
    Node * m_root;
    int m_num_bits;
    vector<int> m_mask;
};

int main()
{
    int t, n, q;
    int a, l ,r;
    
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        
        vector<int> arr(n);
        for (int pos = 0; pos < n; ++pos)
        {
            cin >> arr[pos];
        }
        
        Trie trie(arr);
        while (q--)
        {
            cin >> a >> l >> r;
            cout << trie.max_xor(a, l - 1, r - 1) << endl;
        }
    }
    return 0;
}

