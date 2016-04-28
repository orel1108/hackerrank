#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<long long int> candies(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> candies[pos];
    }
    
    sort(candies.begin(), candies.end());
    
    long long int s = (k - 1) * candies[k - 1];
    for (int pos = 0; pos < k - 1; ++pos)
    {
        s += (2 * pos + 1 - k) * candies[pos];
    }
    
    
    vector<long long int> psums(n + 1);
    for (int pos = 0; pos < n; ++pos)
    {
        psums[pos + 1] = psums[pos] + candies[pos];
    }
    
    long long int ans = numeric_limits<long long int>::max();
    for (int pos = 0; pos < n - k; ++pos)
    {
        if (s < ans)
        {
            ans = s;
        }
        s += (k - 1) * (candies[pos + k] + candies[pos]);
        s -= 2 * (psums[pos + k] - psums[pos + 1]);
    }
    
    if (s < ans)
    {
        ans = s;
    }
    
    cout << ans << endl;
    
    return 0;
}

