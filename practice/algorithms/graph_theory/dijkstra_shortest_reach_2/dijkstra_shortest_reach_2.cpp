#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <queue>
#include <map>
#include <set>

using namespace std;

vector<int> dijkstra(const vector<set<pair<int, int>>> & i_graph, int i_start, int i_n)
{
    vector<int> a(i_n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    
    q.push(make_pair(0, i_start));
    while (!q.empty())
    {
        pair<int, int> e = q.top();
        q.pop();
        
        int plen = e.first;
        int vert = e.second;
        
        if (a[vert] == -1)
        {
            a[vert] = plen;
            set<pair<int, int>>::const_iterator cit = i_graph.at(vert).begin();
            for (; cit != i_graph.at(vert).end(); ++cit)
            {
                int w = cit->first;
                int elen = cit->second;
                if (a[w] == -1)
                {
                    q.push(make_pair(plen + elen, w));
                }
            }
        }
    }
    
    return a;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
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
        
        vector<int> d = dijkstra(graph, s - 1, n);
        for (int pos = 0; pos < d.size(); ++pos)
        {
            if (d[pos] != 0)
            {
                cout << d[pos] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

