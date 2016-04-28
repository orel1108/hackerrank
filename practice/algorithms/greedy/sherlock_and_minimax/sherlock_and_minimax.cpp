#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    long long int p, q;
    cin >> n;
    
    vector<long long int> a(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> a[pos];
    }
    sort(a.begin(), a.end());
    
    cin >> p >> q;
    
    vector<long long int> candidates;
    candidates.push_back(p);
    candidates.push_back(q);
    
    for (int pos = 0; pos < n - 1; ++pos)
    {
        long long int half = (a[pos] + a[pos + 1]) / 2;
        if (half >= p && half <= q)
        {
            candidates.push_back(half);
        }
    }
    
    long long int max_dist = 0;
    long long int res = 0;
    for (int pos = 0; pos < candidates.size(); ++pos)
    {
        long long int min_dist = abs(a[0] - candidates[pos]);
        for (int ipos = 0; ipos < n; ++ipos)
        {
            long long int diff = abs(a[ipos] - candidates[pos]);
            if (diff < min_dist)
            {
                min_dist = diff;
            }
        }
        
        if (min_dist > max_dist)
        {
            max_dist = min_dist;
            res = candidates[pos];
        }
    }
    
    cout << res << endl;
    
    return 0;
}

