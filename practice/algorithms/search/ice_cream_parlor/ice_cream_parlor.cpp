#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{    
    int t, m, n;
    cin >> t;
    
    while(t--)
    {    
        cin >> m >> n;
        
        vector<int> arr(n);
        for(int pos = 0; pos < n; ++pos)
        {
            cin >> arr[pos];
        }
        
        for(int pos = 0; pos < n; ++pos)
        {
            for(int k = pos + 1; k < n; ++k)
            {    
                if((arr[pos] + arr[k]) == m)
                {
                    cout << (pos + 1) << " " << (k + 1) << endl;
                }
            }
        }
    }
    return 0;
}

