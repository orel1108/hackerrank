#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long max_prof(vector<long long>::const_iterator i_begin, vector<long long>::const_iterator i_end)
{
    long long res_prof = 0LL;
    if (distance(i_begin, i_end) > 0)
    {
        int max_pos = distance(i_begin, max_element(i_begin, i_end));
        if (max_pos > 0)
        {
            for (int pos = 0; pos < max_pos; ++pos)
            {
                res_prof -= *i_begin;
                ++i_begin;
            }
            res_prof += max_pos * *i_begin;
        }
        res_prof += max_prof(i_begin + 1, i_end);
    }
    
    return res_prof;
}

int main()
{
    int t, n;
    cin >> t;
    
    while (t--)
    {
        cin >> n;
        
        vector<long long> prices(n);
        for (int pos = 0; pos < n; ++pos)
        {
            cin >> prices[pos];
        }
        
        cout << max_prof(prices.begin(), prices.end()) << endl;
    }
    return 0;
}

