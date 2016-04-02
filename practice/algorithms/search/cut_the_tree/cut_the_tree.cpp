#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <numeric>

using namespace std;

pair<vector<int>, vector<int>> bfs(const vector<set<int>> & i_graph, int i_start, int i_size)
{
    vector<bool> visited(i_size, false);
    vector<int> visit_order;
    
    vector<int> parent(i_size, -1);
    
    queue<int> q;
    q.push(i_start);
    
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        
        if (!visited[node])
        {
            visited[node] = true;
            visit_order.push_back(node);
            
            set<int>::iterator it = i_graph[node].begin();
            for (; it != i_graph[node].end(); ++it)
            {
                if (!visited[*it])
                {
                    q.push(*it);
                    parent[*it] = node;
                }
            }
        }
    }
    
    return make_pair(parent, visit_order);
}

vector<set<int>> make_graph(const vector<pair<int, int>> & i_edges, int i_size)
{
    vector<set<int>> graph(i_size);
    
    vector<pair<int, int>>::const_iterator it = i_edges.begin();
    for (; it != i_edges.end(); ++it)
    {
        graph[it->first].insert(it->second);
        graph[it->second].insert(it->first);
    }
    
    return graph;
}

int main()
{
    int n, v1, v2;
    
    cin >> n;
    
    vector<int> weights(n);
    for (std::size_t pos = 0; pos < n; ++pos)
    {
        cin >> weights[pos];
    }
    
    vector<pair<int, int>> edges;
    for (int cnt = 0; cnt < n - 1; ++cnt)
    {
        cin >> v1 >> v2;
        edges.push_back(make_pair(v1 - 1, v2 - 1));
    }
    
    const int total = accumulate(weights.begin(), weights.end(), 0);
    
    vector<set<int>> graph = make_graph(edges, n);
    
    pair<vector<int>, vector<int>> bfs_res = bfs(graph, 0, n);
    
    vector<int> parent = bfs_res.first;
    vector<int> visit_order = bfs_res.second;
    
    vector<int> sums(n, 0);
    
    vector<int>::reverse_iterator rit = visit_order.rbegin();
    for (; rit != visit_order.rend(); ++rit)
    {
        sums[*rit] += weights[*rit];
        int p = parent[*rit];
        if (p != -1)
        {
            sums[p] += sums[*rit];
        }
    }
    
    int res = total;
    for (int cnt = 0; cnt < n; ++cnt)
    {
        res = min(res, abs(2 * sums[cnt] - total));
    }
    
    cout << res;
    
    return 0;
}

