#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool contains(const vector<string> & grid, const vector<string> & pattern, int row, int col)
{
    const size_t R = grid.size();
    const size_t C = grid[0].size();
    const size_t r = pattern.size();
    const size_t c = pattern[0].size();
    
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            size_t ir = i + row;
            size_t jc = j + col;
            if (ir >= R || jc >= C)
            {
                return false;
            }
            if (grid[ir][jc] != pattern[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int t, R, C, r, c;
    cin >> t;
    while (t--) 
    {
        cin >> R >> C;
        vector<string> table(R);
        for (int x = 0; x < R; x++)
        {
            cin >> table[x];    
        }
        
        cin >> r >> c;
        vector<string> pattern(r);
        for (int x = 0; x < r; x++)
        {
            cin >> pattern[x];    
        }
        
        bool ans = false;
        for (int row = 0; row < R; row++)
        {
            for (int col = 0; col < C; col++)
            {
                if (contains(table, pattern, row, col))
                {
                    ans = true;
                    break;
                }
            }
            if (ans)
            {
                break;
            }
        }
        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}

