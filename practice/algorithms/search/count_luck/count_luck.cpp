#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <string>

using namespace std;

set<pair<int, int>> VISITED;
map<pair<int, int>, int> TRACK;

void dfs(const map<pair<int, int>, set<pair<int, int>>> & i_graph, pair<int, int> i_start, pair<int, int> i_end)
{
    if (i_start == i_end)
    {
        return;
    }
    
    VISITED.insert(i_start);
    
    vector<pair<int, int>> neighbors;
    set<pair<int, int>>::const_iterator it = i_graph.at(i_start).begin();
    for (; it != i_graph.at(i_start).end(); ++it)
    {
        if (VISITED.find(*it) == VISITED.end())
        {
            neighbors.push_back(*it);
        }
    }
    
    if (neighbors.size() > 1)
    {
        if (TRACK.find(i_start) == TRACK.end())
        {
            TRACK[i_start] = 0;
        }
        TRACK[i_start]++;
    }
    
    vector<pair<int, int>>::iterator vit = neighbors.begin();
    for (; vit != neighbors.end(); ++vit)
    {
        TRACK[*vit] = TRACK[i_start];
        dfs(i_graph, *vit, i_end);
    }
}

int main()
{
    int t, n, m, k;
    cin >> t;
    
    while (t--)
    {
        cin >> n >> m;
        
        vector<string> forest(n);
        for (int cnt = 0; cnt < n; ++cnt)
        {
            cin >> forest[cnt];
        }
        
        pair<int, int> start(0, 0);
        pair<int, int> end(0, 0);
        
        map<pair<int, int>, set<pair<int, int>>> graph;
        
        for (int row = 0; row < n; ++row)
        {
            for (int col = 0; col < m; ++col)
            {
                if (forest[row][col] != 'X')
                {
                    pair<int, int> center(row, col);
                    pair<int, int> up(row - 1, col);
                    pair<int, int> down(row + 1, col);
                    pair<int, int> left(row, col - 1);
                    pair<int, int> right(row, col + 1);
                    
                    if (row > 1 && forest[row - 1][col] != 'X')
                    {
                        if (graph.find(center) == graph.end())
                        {
                            graph[center] = set<pair<int, int>>();
                        }
                        graph[center].insert(up);
                        
                        if (graph.find(up) == graph.end())
                        {
                            graph[up] = set<pair<int, int>>();
                        }
                        graph[up].insert(center);
                    }
                    
                    if (row < n - 1 && forest[row + 1][col] != 'X')
                    {
                        if (graph.find(center) == graph.end())
                        {
                            graph[center] = set<pair<int, int>>();
                        }
                        graph[center].insert(down);
                        
                        if (graph.find(down) == graph.end())
                        {
                            graph[down] = set<pair<int, int>>();
                        }
                        graph[down].insert(center);
                    }
                    
                    if (col > 1 && forest[row][col - 1] != 'X')
                    {
                        if (graph.find(center) == graph.end())
                        {
                            graph[center] = set<pair<int, int>>();
                        }
                        graph[center].insert(left);
                        
                        if (graph.find(left) == graph.end())
                        {
                            graph[left] = set<pair<int, int>>();
                        }
                        graph[left].insert(center);
                    }
                    
                    if (col < m - 1 && forest[row][col + 1] != 'X')
                    {
                        if (graph.find(center) == graph.end())
                        {
                            graph[center] = set<pair<int, int>>();
                        }
                        graph[center].insert(right);
                        
                        if (graph.find(right) == graph.end())
                        {
                            graph[right] = set<pair<int, int>>();
                        }
                        graph[right].insert(center);
                    }
                    
                    if (forest[row][col] == 'M')
                    {
                        start = make_pair(row, col);
                    }
                    if (forest[row][col] == '*')
                    {
                        end = make_pair(row, col);
                    }
                }
            }
        }
        
        cin >> k;
        VISITED = set<pair<int, int>> ();
        TRACK = map<pair<int, int>, int>();
        TRACK[start] = 0;
        
        dfs(graph, start, end);
        
        if (k == TRACK[end])
        {
            cout << "Impressed" << endl;
        }
        else
        {
            cout << "Oops!" << endl;
        }
    }
    
    return 0;
}

