#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector< vector<int> > matrix(n,vector<int>(n));
    for(int i = 0; i < n; i++)
    {
       for(int j = 0; j < n; j++)
       {
          cin >> matrix[i][j];
       }
    }
    
    int diag = 0;
    int codiag = 0;
    
    for (int i = 0; i < n; i++)
    {
        diag += matrix[i][i];
        codiag += matrix[n - 1 - i][i];
    }
    
    int res = abs(diag - codiag);
    cout << res << endl;
    return 0;
}

