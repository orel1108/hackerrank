#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int t, n, k, v;
    cin >> t;
    
    while (t--)
    {
        cin >> n >> k;
        
        set<int> b;
        for (int pos = 0; pos < n; ++pos)
        {
            cin >> v;
            if (v <= k)
            {
                b.insert(v);
            }
        }
        
        vector<int> dp(k + 1);
        set<int>::const_iterator it;
        for (int pos = 1; pos < k + 1; ++pos)
        {
            it = b.begin();
            for (; it != b.end(); ++it)
            {
                if (pos >= *it)
                {
                    dp[pos] = max(dp[pos], *it + dp[pos - *it]);
                }
            }
        }
        
        cout << dp[k] << endl;
    }
    
    return 0;
}

