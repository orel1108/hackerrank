#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <string>

using namespace std;

set<pair<int, int>> find_neighbors(const vector<vector<int>> & i_matrix, int i_row, int i_col, int i_m, int i_n)
{
    set<pair<int, int>> neighbors;
    for (int row = i_row - 1; row < i_row + 2; ++row)
    {
        for (int col = i_col - 1; col < i_col + 2; ++col)
        {
            if (row > -1 && row < i_m && col > -1 && col < i_n)
            {
                if ((row != i_row || col != i_col) && i_matrix[row][col] == 1)
                {
                    neighbors.insert(make_pair(row, col));
                }
            }
        }
    }
    
    return neighbors;
}

void dfs(map<pair<int, int>, set<pair<int, int>>> & i_graph, pair<int, int> i_start, set<pair<int, int>> & io_visited)
{
    io_visited.insert(i_start);
    
    set<pair<int, int>>::iterator it = i_graph[i_start].begin();
    for (; it != i_graph[i_start].end(); ++it)
    {
        if (io_visited.find(*it) == io_visited.end())
        {
            dfs(i_graph, *it, io_visited);
        }
    }
}

int main()
{
    int n, m;
    cin >> m >> n;
    
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int row = 0; row < m; ++row)
    {
        for (int col = 0; col < n; ++col)
        {
            cin >> matrix[row][col];    
        }    
    }
    
    map<pair<int, int>, set<pair<int, int>>> graph;
    vector<pair<int, int>> vertices;
    
    for (int row = 0; row < m; ++row)
    {
        for (int col = 0; col < n; ++col)
        {
            if (matrix[row][col] == 1)
            {
                vertices.push_back(make_pair(row, col));
                set<pair<int, int>> neighbors = find_neighbors(matrix, row, col, m, n);
                graph[make_pair(row, col)] = neighbors;
            }
        }    
    }
    
    int reg_size = 0;
    for (int pos = 0; pos < vertices.size(); ++pos)
    {
        set<pair<int, int>> visited;
        dfs(graph, vertices[pos], visited);
        if (visited.size() > reg_size)
        {
            reg_size = visited.size();
        }
    }
    
    cout << reg_size << endl;
    
    return 0;
}

