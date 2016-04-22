#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <limits>

using namespace std;

struct Edge
{
    int v1, v2, w;
};

vector<Edge> prim_mst(const vector<set<pair<int, int>>> & i_graph, int i_s, int i_n)
{
    set<int> visited;
    visited.insert(i_s);
    
    vector<Edge> mst;
    
    for (int cnt = 0; cnt < i_n - 1; ++cnt)
    {
        int m = numeric_limits<int>::max();
        int v;
        Edge e;
        
        set<int>::iterator it = visited.begin();
        for (; it != visited.end(); ++it)
        {
            set<pair<int, int>>::iterator eit = i_graph[*it].begin();
            for (; eit != i_graph[*it].end(); ++eit)
            {
                if (visited.find(eit->first) == visited.end())
                {
                    int w = eit->second;
                    if (w < m)
                    {
                        m = w;
                        v = eit->first;
                        e.v1 = *it;
                        e.v2 = v;
                        e.w = m;
                    }
                }
            }
        }
        
        visited.insert(v);
        mst.push_back(e);
    }
    
    return mst;
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<set<pair<int, int>>> graph(n);
    while (m--)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        graph[v1 - 1].insert(make_pair(v2 - 1, w));
        graph[v2 - 1].insert(make_pair(v1 - 1, w));
    }
    
    int s;
    cin >> s;
    
    vector<Edge> mst = prim_mst(graph, s - 1, n);
    int res = 0;
    for (int pos = 0; pos < mst.size(); ++pos)
    {
        res += mst[pos].w;
    }
    cout << res << endl;
    
    return 0;
}

