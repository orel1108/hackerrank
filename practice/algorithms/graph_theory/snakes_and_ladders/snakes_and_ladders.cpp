#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <map>

using namespace std;

int shortest_path(const vector<set<int>> & i_graph)
{
    vector<int> dists(100, 1000000);
    vector<bool> visited(100, false);
    
    dists[0] = 0;
    visited[0] = true;
    
    queue<int> q;
    q.push(0);
    
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        visited[vertex] = true;
        if (vertex == 99)
        {
            return dists[vertex];
        }
        
        set<int>::const_iterator it = i_graph[vertex].begin();
        for (; it != i_graph[vertex].end(); ++it)
        {
            if (!visited[*it])
            {
                dists[*it] = min(dists[*it], dists[vertex] + 1);
                q.push(*it);
            }
        }
    }
    return -1;
}

int main()
{
    int t, num_ladders, num_snakes;
    int s, e;
    cin >> t;

    while (t--)
    {
        map<int, int> ladders, snakes;
        cin >> num_ladders;
        while (num_ladders--)
        {
            cin >> s >> e;
            ladders[s - 1] = e - 1;
        }
        
        cin >> num_snakes;
        while (num_snakes--)
        {
            cin >> s >> e;
            snakes[s - 1] = e - 1;
        }
        
        vector<set<int>> graph(100);
        for (int start = 0; start < 100; ++start)
        {
            for (int end = start + 1; end < start + 7; ++end)
            {
                if (ladders.find(end) != ladders.end())
                {
                    graph[start].insert(ladders[end]);
                }
                if (snakes.find(end) != snakes.end())
                {
                    graph[start].insert(snakes[end]);
                }
            }
            int end = min(start + 6, 99);
            if (ladders.find(end) == ladders.end() && snakes.find(end) == snakes.end())
            {
                graph[start].insert(end);
            }
        }
    
        cout << shortest_path(graph) << endl;
    }
    
    return 0;
}

