#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    
    const size_t n = s1.length();
    
    vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));
    for (size_t row = 1; row < n + 1; row++)
    {
        for (size_t col = 1; col < n + 1; col++)
        {
            if (s1[row - 1] != s2[col - 1])
            {
                table[row][col] = max(table[row][col - 1], table[row - 1][col]);
            }
            else
            {
                table[row][col] = table[row - 1][col - 1] + 1;
            }
        }
    }
    
    cout << table[n][n] << endl;
    
    return 0;
}

