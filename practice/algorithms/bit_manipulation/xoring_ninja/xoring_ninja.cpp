#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    
    const int MOD = 1000000007;
    
    while (t--)
    {
        cin >> n;
        
        vector<int> arr(n);
        for (int pos = 0; pos < n; ++pos)
        {
            cin >> arr[pos];
        }
        
        int s = 0;
        for (int pos = 0; pos < n; ++pos)
        {
            s |= arr[pos];
        }
        
        for (int cnt = 0; cnt < n - 1; ++cnt)
        {
            s <<= 1;
            if (s >= MOD)
            {
                s %= MOD;
            }
        }
        
        cout << s << endl;
    }
    return 0;
}

