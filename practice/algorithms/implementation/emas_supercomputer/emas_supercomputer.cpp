#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

vector<int> find_plus_sizes(const vector<string> & i_grid, int i_row, int i_col)
{
    const int n = i_grid.size();
    const int m = i_grid[0].size();
    
    int k = 0, d = 0;
    vector<int> sizes;
    while (true)
    {
        vector<pair<int, int>> neighbors;
        neighbors.push_back(make_pair(i_row - k, i_col));
        neighbors.push_back(make_pair(i_row + k, i_col));
        neighbors.push_back(make_pair(i_row, i_col - k));
        neighbors.push_back(make_pair(i_row, i_col + k));
        
        for (vector<pair<int, int>>::const_iterator it = neighbors.begin(); it != neighbors.end(); ++it)
        {
            if ((-1 < it->first) && (it->first < n) &&
                (-1 < it->second) && (it->second < m))
            {
                if (i_grid[it->first][it->second] != 'G')
                {
                    return sizes;
                }
            }
            else
            {
                return sizes;
            }
        }
        k++;
        d++;
        sizes.push_back(d);
    }
    
    return sizes;
}

bool intersects(const pair<int, pair<int, int>> & i_plus1, const pair<int, pair<int, int>> & i_plus2)
{
    set<pair<int, int>> s1, s2;
    int x, y;
    
    x = i_plus1.second.first;
    y = i_plus1.second.second;
    for (int k = 0; k < i_plus1.first; ++k)
    {
        s1.insert(make_pair(x - k, y));
        s1.insert(make_pair(x + k, y));
        s1.insert(make_pair(x, y - k));
        s1.insert(make_pair(x, y + k));
    }
    
    x = i_plus2.second.first;
    y = i_plus2.second.second;
    for (int k = 0; k < i_plus2.first; ++k)
    {
        s2.insert(make_pair(x - k, y));
        s2.insert(make_pair(x + k, y));
        s2.insert(make_pair(x, y - k));
        s2.insert(make_pair(x, y + k));
    }
    
    for (set<pair<int, int>>::const_iterator it = s1.begin(); it != s1.end(); ++it)
    {
        if (s2.find(*it) != s2.end())
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> grid[pos];
    }
    
    vector<pair<int, pair<int, int>>> pluses;
    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < m; ++col)
        {
            if (grid[row][col] == 'G')
            {
                vector<int> sizes = find_plus_sizes(grid, row, col);
                for (int pos = 0; pos < sizes.size(); ++pos)
                {
                    pluses.push_back(make_pair(sizes[pos], make_pair(row, col)));
                }
            }
        }
    }
    
    int res = 0;
    for (int i = 0; i < pluses.size(); ++i)
    {
        for (int j = i + 1; j < pluses.size(); ++j)
        {
            if (!intersects(pluses[i], pluses[j]))
            {
                int d = (4 * (pluses[i].first - 1) + 1) * (4 * (pluses[j].first - 1) + 1);
                if (d > res)
                {
                    res = d;
                }
            }
        }
    }
    
    cout << res << endl;
    
    return 0;
}

