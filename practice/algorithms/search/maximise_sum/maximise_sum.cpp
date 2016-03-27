#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    
    int t, n;
    long long m;
    cin >> t;
    long long a[100001];
    for (int i = 0; i < t; ++i)
    {
        cin >> n >> m;
        for (int j = 0; j < n; ++j)
        {
            cin >> a[j];
        }
        
        vector<long long> part(n);
        part[0] = a[0] % m;
        for (int j = 1; j < n; ++j)
        {
            part[j] = (part[j - 1] + a[j]) % m;
        }
        
        vector<int> diffs;
        set<long long> s;
        for (int j = 0; j < n; ++j)
        {
            s.insert(part[j]);
            set<long long>::iterator it = s.upper_bound(part[j]);
            if (it != s.end())
            {
                int v = part[j] - *it;
                if (v < 0)
                    diffs.push_back(v);
            }
        }
        
        long long res = max(*max_element(part.begin(), part.end()), m + *max_element(diffs.begin(), diffs.end()));
        cout << res << endl;
        
    }
    return 0;
}

