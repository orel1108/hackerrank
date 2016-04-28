#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    
    vector<int> buff(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> buff[pos];
    }
    
    sort(buff.begin(), buff.end());
    
    int res = buff[k - 1] - buff[0];
    for (int pos = 1; pos < n - k + 1; ++pos)
    {
        int diff = buff[pos + k - 1] - buff[pos];
        if (diff < res)
        {
            res = diff;
        }
    }
    
    cout << res << endl;
    
    return 0;
}

