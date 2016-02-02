#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

char findCavity(const vector<string> & grid, int row, int col, int n)
{
    if (row == 0 || row == n - 1)
        return grid[row][col];
    if (col == 0 || col == n - 1)
        return grid[row][col];
    
    if (grid[row - 1][col] >= grid[row][col])
        return grid[row][col];
    if (grid[row + 1][col] >= grid[row][col])
        return grid[row][col];
    if (grid[row][col - 1] >= grid[row][col])
        return grid[row][col];
    if (grid[row][col + 1] >= grid[row][col])
        return grid[row][col];
    
    return 'X';
}

int main()
{
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i = 0; i < n; i++)
    {
       cin >> grid[i];
    }
    
    vector<string> rgrid(n, string(n, ' '));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rgrid[i][j] = findCavity(grid, i, j, n);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << rgrid[i] << endl;
    }
    
    return 0;
}

