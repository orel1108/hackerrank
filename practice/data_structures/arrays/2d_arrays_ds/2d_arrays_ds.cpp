#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    vector<vector<int>> arr(6, vector<int>(6));
    for (int row = 0; row < 6; ++row)
    {
       for (int col = 0; col < 6; ++col)
       {
          cin >> arr[row][col];
       }
    }
    
    int m = -50;
    for (int row = 0; row < 4; ++row)
    {
        for (int col = 0; col < 4; ++col)
        {
            int s = accumulate(arr[row].begin() + col, arr[row].begin() + col + 3, 0) + 
                    accumulate(arr[row + 2].begin() + col, arr[row + 2].begin() + col + 3, 0) + 
                    arr[row + 1][col + 1];
            if (s > m)
            {
                m = s;
            }
        }
    }
    
    cout << m << endl;
    
    return 0;
}

