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
        
        int m = 1000;
        vector<int> a(n);
        for (int pos = 0; pos < n; ++pos)
        {
            cin >> a[pos];
            if (a[pos] < m)
            {
                m = a[pos];
            }
        }
        
        long long int ans = 1000000000LL;
        vector<int> r = {m, m - 1, m - 2, m - 5};
        
        for (int pos = 0; pos < 4; ++pos)
        {
            long long int cnt = 0;
            vector<int>::const_iterator it = a.begin();
            for (; it != a.end(); ++it)
            {
                int c = *it - r[pos];
                cnt += c / 5 + (c % 5) / 2 + (c % 5) % 2;
            }
            if (cnt < ans)
            {
                ans = cnt;
            }
        }
        
        cout << ans << endl;
        
    }
    return 0;
}

