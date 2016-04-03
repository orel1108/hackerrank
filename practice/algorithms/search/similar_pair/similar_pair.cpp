#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <numeric>
#include <stack>

using namespace std;

int Get(const vector<int> & i_b, int i_pos)
{
    int res = 0;
    
    i_pos++;
    while (i_pos)
    {
        res += i_b[i_pos - 1];
        i_pos -= (i_pos & -i_pos);
    }
    
    return res;
}

void Set(vector<int> & i_b, int i_pos, int i_n, int i_val)
{
    i_pos++;
    while (i_pos <= i_n)
    {
        i_b[i_pos - 1] += i_val;
        i_pos += (i_pos & -i_pos);
    }
}

long long dfs(const vector<set<int>> & i_graph, int i_start, int i_n, int i_t)
{
    long long pairs = 0;
    
    vector<int> colors(i_n);
    vector<int> ancestors(i_n);
    
    stack<int> st;
    st.push(i_start);
    while (!st.empty())
    {
        int node = st.top();
        if (colors[node] == 0)
        {
            colors[node] = 1;
        }
        else
        {
            colors[node] = 2;
            st.pop();
        }
        
        int v = Get(ancestors, node);
        if (node > 0)
        {
            v -= Get(ancestors, node - 1);
        }
        Set(ancestors, node, i_n, 1 - v);
        
        if (i_graph[node].size() > 0)
        {
            set<int>::iterator it = i_graph[node].begin();
            for (; it != i_graph[node].end(); ++it)
            {
                if (colors[*it] == 0)
                {
                    st.push(*it);
                }
            }    
        }
        
        if (colors[node] == 2)
        {
            int left = max(0, node - i_t);
            int right = min(i_n, node + i_t);
            
            v = Get(ancestors, node);
            if (node > 0)
            {
                v -= Get(ancestors, node - 1);
            }
            
            if (v > 0 && (right < i_n - 1))
            {
                right++;
            }
            
            Set(ancestors, node, i_n, -v);
            
            int B = Get(ancestors, right - 1);
            if (left > 0)
            {
                B -= Get(ancestors, left - 1);    
            }
            
            pairs += B;
        }
    }

    return pairs;    
}

int main()
{
    int n, t, v1, v2;
    cin >> n >> t;
    
    set<int> children;
    vector<set<int>> graph(n);
    for (int cnt = 0; cnt < n - 1; ++cnt)
    {
        cin >> v1 >> v2;
        children.insert(v2 - 1);
        graph[v1 - 1].insert(v2 - 1);
    }
    
    long long root = (n - 1) * n / 2 - accumulate(children.begin(), children.end(), 0);
    long long pairs = dfs(graph, root, n, t);
    
    cout << pairs << endl;
    
    return 0;
}

