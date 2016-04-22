#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;

vector<vector<unsigned>> floyd(const map<pair<int, int>, unsigned> & i_graph, int i_n)
{
    vector<vector<unsigned>> dists(i_n, vector<unsigned>(i_n, 1000000000U));
    for (int v = 0; v < i_n; v++)
    {
        dists[v][v] = 0U;
    }
    
    for (auto EDGE : i_graph)
    {
        dists[EDGE.first.first][EDGE.first.second] = EDGE.second;
    }
    
    for (int k = 0; k < i_n; k++)
    {
        for (int i = 0; i < i_n; i++)
        {
            for (int j = 0; j < i_n; j++)
            {
                dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
            }
        }
    }
    return dists;
}

int main()
{
    int n, m, q;
    cin >> n >> m;
    
    map<pair<int, int>, unsigned> graph;
    int x, y;
    unsigned w;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        auto r = graph.insert(make_pair(make_pair(x - 1, y - 1), w));
        if (!r.second)
        {
            graph[make_pair(x - 1, y - 1)] = w;
        }
    }
    
    vector<vector<unsigned>> dists = floyd(graph, n);
    
    cin >> q;
    int a, b;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        unsigned d = dists[a - 1][b - 1];
        if (d < 1000000000U)
        {
            cout << d << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    
    return 0;
}

