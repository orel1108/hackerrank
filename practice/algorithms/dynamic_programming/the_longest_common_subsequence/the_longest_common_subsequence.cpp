#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> a[pos];
    }
    
    vector<int> b(n);
    for (int pos = 0; pos < m; ++pos)
    {
        cin >> b[pos];
    }
    
    vector<vector<int>> c(m + 1, vector<int>(n + 1));
    for (int row = 1; row < m + 1; ++row)
    {
        for (int col = 1; col < n + 1; ++col)
        {
            if (a[col - 1] == b[row - 1])
            {
                c[row][col] = c[row - 1][col - 1] + 1;
            }
            else
            {
                c[row][col] = max(c[row - 1][col], c[row][col - 1]);
            }
        }
    }
    
    vector<int> res;
    while (n != 0 && m != 0)
    {
        if (c[m][n] == c[m - 1][n])
        {
            m--;
        }
        else if (c[m][n] == c[m][n - 1])
        {
            n--;   
        }
        else
        {
            res.push_back(b[m - 1]);
            n--;
            m--;
        }
    }
    
    vector<int>::reverse_iterator rit = res.rbegin();
    for (; rit != res.rend(); ++rit)
    {
        cout << *rit << " ";
    }
    cout << endl;
    
    return 0;
}

