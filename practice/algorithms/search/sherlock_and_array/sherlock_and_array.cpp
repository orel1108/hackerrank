#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    
    while (t--)
    {
        cin >> n;
        vector<int> arr(n);
        
        for (int pos = 0; pos < n; ++pos)
        {
            cin >> arr[pos];
        }
        
        int lcnt = 0, rcnt = n - 1;
        int lsum = 0, rsum = 0;
        
        while (lcnt < rcnt)
        {
            if (lsum <= rsum)
            {
                lsum += arr[lcnt++];
            }
            else
            {
                rsum += arr[rcnt--];
            }
        }
        if (lcnt == rcnt && lsum == rsum)
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

