#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int cadane(const vector<int> & i_a)
{
    int curr_max = i_a[0], res_max = i_a[0];
    for (int pos = 1; pos < i_a.size(); ++pos)
    {
        curr_max = max(i_a[pos], curr_max + i_a[pos]);
        res_max = max(res_max, curr_max);
    }
    return res_max;
}

int main()
{
    int t, n;
    cin >> t;
    
    while (t--)
    {
        cin >> n;
        
        vector<int> a(n);
        for (int pos = 0; pos < n; ++pos)
        {
            cin >> a[pos];
        }
        
        const int m = *max_element(a.begin(), a.end());
        int res = 0;
        if (m <= 0)
        {
            res = m;
        }
        else
        {
            res = accumulate(a.begin(), a.end(), 0, 
                             [](int i_a, int i_b)
                             {
                                 return i_b >= 0 ? (i_a + i_b) : i_a;
                             });
        }
        
        cout << cadane(a) << " " << res << endl;
    }
    return 0;
}

