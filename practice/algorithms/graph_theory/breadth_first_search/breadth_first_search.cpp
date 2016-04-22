#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

vector<int> bfs(const vector<set<int>> & i_graph, int i_start, int i_n)
{
    vector<int> distances(i_n, 0);
    vector<bool> visited(i_n, false);
    visited[i_start] = true;
    
    queue<int> q;
    q.push(i_start);
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        
        set<int>::const_iterator it = i_graph[vertex].begin();
        for (; it != i_graph[vertex].end(); ++it)
        {
            if (!visited[*it])
            {
                distances[*it] = distances[vertex] + 1;
                q.push(*it);
                visited[*it] = true;    
            }
        }
    }
    
    return distances;
}

int main()
{
    int t, n, m;
    int v, w, s;
    cin >> t;
    
    while (t--)
    {
        cin >> n >> m;
        
        vector<set<int>> graph(n);
        while (m--)
        {
            cin >> v >> w;
            graph[v - 1].insert(w - 1);
            graph[w - 1].insert(v - 1);
        }
        
        cin >> s;
        vector<int> dist = bfs(graph, s - 1, n);
        
        for (int pos = 0; pos < n; ++pos)
        {
            if (pos != s - 1)
            {
                if (dist[pos] == 0)
                {
                    cout << -1 << " ";
                }
                else
                {
                    cout << (6 * dist[pos]) << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}

