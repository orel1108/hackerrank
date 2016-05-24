#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

class Heap
{
public:
    Heap()
        : m_size(0)
    {}
    
    void insert(int i_val)
    {
        m_data[++m_size] = i_val;
        m_pos[i_val] = m_size;
        if (m_size > 0)
        {
            int pos = m_size;
            while (pos > 1)
            {
                if (m_data[pos] < m_data[pos / 2])
                {
                    m_pos[m_data[pos]] = pos / 2;
                    m_pos[m_data[pos / 2]] = pos;
                    swap(m_data[pos], m_data[pos / 2]);
                    pos /= 2;
                }
                else
                {
                    break;
                }
            }
        }
    }
    
    void remove(int i_val)
    {
        int idx = m_pos[i_val];
        m_pos[i_val] = 0;
        m_pos[m_data[m_size]] = idx;
        m_data[idx] = m_data[m_size--];
        
        while (true)
        {
            int l = 2 * idx, r = 2 * idx + 1;
            if (l <= m_size)
            {
                if (r < m_size)
                {
                    if (m_data[idx] > m_data[l] || m_data[idx] > m_data[r])
                    {
                        int sidx = (m_data[l] < m_data[r]) ? l : r;
                        m_pos[m_data[sidx]] = idx;
                        m_pos[m_data[idx]] = sidx;
                        swap(m_data[idx], m_data[sidx]);
                        idx = sidx;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if (m_data[idx] > m_data[l])
                    {
                        m_pos[m_data[l]] = idx;
                        m_pos[m_data[idx]] = l;
                        swap(m_data[idx], m_data[l]);
                        idx = l;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                break;
            }
        }
    }
    
    int min_val() const
    {
        return m_data[1];
    }
    
private:
    map<int, int> m_pos;
    int m_data[100000];
    int m_size;
};

int main()
{
    int q, v, t;
    Heap heap;
    
    cin >> q;
    while (q--)
    {
        cin >> v;
        if (v == 1)
        {
            cin >> t;
            heap.insert(t);
        }
        else if (v == 2)
        {
            cin >> t;
            heap.remove(t);
        }
        else
        {
            cout << heap.min_val() << endl;
        }
    }
    
    return 0;
}

