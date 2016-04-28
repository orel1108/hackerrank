#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> c(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> c[pos];
    }
    
    sort(c.begin(), c.end(), greater<int>());
    
    int res = 0;
    if (n <= k)
    {
        res = accumulate(c.begin(), c.end(), 0);
    }
    else
    {
        int cnt = 1;
        int j = 0;
        while (j < n)
        {
            res += cnt * accumulate(c.begin() + j, c.begin() + min(j + k, n), 0);
            j += k;
            cnt++;
        }
    }
    
    cout << res << endl;
    
    return 0;
}

