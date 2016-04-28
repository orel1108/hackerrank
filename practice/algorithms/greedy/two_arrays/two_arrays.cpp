#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t, n, k;
    cin >> t;
    
    while (t--)
    {
        cin >> n >> k;
        
        vector<int> a(n);
        vector<int> b(n);
        
        for (int pos = 0; pos < n; ++pos)
        {
            cin >> a[pos];
        }
        
        for (int pos = 0; pos < n; ++pos)
        {
            cin >> b[pos];
        }
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        bool ans = true;
        for(int pos = 0; pos < n; ++pos)
        {
            if(( a[pos] + b[n - pos - 1]) < k)
            {
                ans = false;
                break;
            }
        }
        
        if (ans)
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

