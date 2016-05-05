#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> find_lis(const vector<int> & i_arr)
{
    if (i_arr.empty())
    {
        return vector<int>();
    }
    
    vector<int> p(i_arr.size());
    
    int u = 0, v = 0;
    
    vector<int> b(1);
    for (int pos = 1; pos < i_arr.size(); ++pos)
    {
        if (i_arr[b[b.size() - 1]] < i_arr[pos])
        {
            p[pos] = b[b.size() - 1];
            b.push_back(pos);
            continue;
        }
        
        u = 0;
        v = b.size();
        while (u < v)
        {
            int c = (u + v) / 2;
            if (i_arr[b[c]] < i_arr[pos])
            {
                u = c + 1;
            }
            else
            {
                v = c;
            }
        }
        
        if (i_arr[pos] < i_arr[b[u]])
        {
            if (u > 0)
            {
                p[pos] = b[u - 1];
            }
            b[u] = pos;
        }
    }
    
    u = b.size() - 1;
    v = b[u];
    while (u > 0)
    {
        b[u] = v;
        v = p[v];
        u--;
    }
    
    return b;
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> arr[pos];
    }
    
    vector<int> lis = find_lis(arr);
    cout << lis.size() << endl;
    
    return 0;
}

