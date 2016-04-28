#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool solve(const vector<string> & i_matrix, int i_n)
{
    int col = 0;
    while (col < i_n)
    {
        for (int row = 1; row < i_n; ++row)
        {
            if (i_matrix[row][col] < i_matrix[row - 1][col])
            {
                return false;
            }
        }
        col++;
    }
    return true;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<string> matrix(n);
        string row;
        for (int cnt = 0; cnt < n; ++cnt)
        {
            cin >> row;
            sort(row.begin(), row.end());
            matrix[cnt] = row;
        }
        
        bool ans = solve(matrix, n);
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

