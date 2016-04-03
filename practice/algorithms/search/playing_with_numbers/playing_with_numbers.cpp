#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// TODO: failed in last cases

int main()
{
    int n, q;
    cin >> n;
    
    vector<long long int> a(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> a[pos];
    }
    
    cin >> q;
    
    vector<long long int> v(q);
    for (int pos = 0; pos < q; ++pos)
    {
        cin >> v[pos];
    }
    
    sort(a.begin(), a.end());
    
    vector<long long int> part_sums(n + 1);
    for (int pos = 0; pos < n; ++pos)
    {
        part_sums[pos + 1] = part_sums[pos] + a[pos];
    }
    
    int x = 0;
    for (int pos = 0; pos < q; ++pos)
    {
        x += v[pos];
        vector<long long int>::iterator it = upper_bound(a.begin(), a.end(), -x);
        int apos = distance(a.begin(), it);
        
        long long int left = part_sums[apos] + x * apos;
        long long int right = part_sums[n] - part_sums[apos] + x * (n - apos);
        long long int res = abs(left) + right;
        cout << res << endl;
    }
    
    return 0;
}

