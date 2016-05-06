#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> int2bin(int i_val, int i_size)
{
    vector<int> res(i_size);
    int pos = i_size - 1;
    while (i_val)
    {
        res[pos] = i_val & 1;
        pos--;
        i_val /= 2;
    }
    return res;
}

int bin2int(const vector<int> & i_bin)
{
    int res = 0;
    for (int pos = 0; pos < i_bin.size(); ++pos)
    {
        res = 2 * res + i_bin[pos];
    }
    return res;
}

bool solve(const vector<int> & i_p)
{
    int n = i_p.size();
    int s = 1 << n;
    
    vector<bool> dp(s, false);
    for (int subs = 1; subs < s; ++ subs)
    {
        vector<int> ss = int2bin(subs, n);
        
        vector<int> arr;
        for (int pos = 0; pos < n; ++pos)
        {
            if (ss[pos] == 1)
            {
                arr.push_back(i_p[pos]);
            }
        }
        
        if (is_sorted(arr.begin(), arr.end()))
        {
            dp[subs] = false;
        }
        else
        {
            int pos = 0;
            while (pos < n)
            {
                if (ss[pos] == 1)
                {
                    ss[pos] = 0;
                    int v = bin2int(ss);
                    ss[pos] = 1;
                    if (!dp[v])
                    {
                        dp[subs] = true;
                        break;
                    }
                }
                pos++;
            }
            if (pos == n)
            {
                dp[subs] = false;
            }
        }
    }
    
    return dp.back();
}

int main()
{
    int t, n;
    cin >> t;
    
    while (t--)
    {
        cin >> n;
        
        vector<int> p(n);
        for (int pos = 0; pos < n; ++pos)
        {
            cin >> p[pos];
        }
        
        if (solve(p))
        {
            cout << "Alice" << endl;
        }
        else
        {
            cout << "Bob" << endl;
        }
    }
    return 0;
}

