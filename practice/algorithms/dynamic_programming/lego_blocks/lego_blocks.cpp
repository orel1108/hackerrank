#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long int pow_mod(long long int i_val, long long int i_pow, long long int i_mod)
{
    long long int res = 1LL;
    while (i_pow > 0)
    {
        if (i_pow & 1LL == 1LL)
        {
            res *= i_val;
        }
        i_val *= i_val;
        
        res %= i_mod;
        i_val %= i_mod;
        
        i_pow >>= 1;
    }
    
    return res;
}

int main()
{
    int t, n, m;
    const int MAX_N = 1000;
    const long long int MOD = 1000000007LL;
    
    vector<long long int> decomp = {0LL, 1LL, 2LL, 4LL, 8LL};
    for (int pos = 1; pos < MAX_N; ++pos)
    {
        long long int v = decomp[pos] + decomp[pos + 1] + decomp[pos + 2] + decomp[pos + 3];
        v %= MOD;
        decomp.push_back(v);
    }
    
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        
        vector<long long int> p;
        for (int pos = 0; pos < m + 1; ++pos)
        {
            p.push_back(pow_mod(decomp[pos], n, MOD));
        }
        
        vector<long long int> r(m + 1, 0LL);
        r[1] = 1LL;
        for (int pos = 2; pos < m + 1; ++pos)
        {
            r[pos] = p[pos];
            for (int ipos = 1; ipos < pos; ++ipos)
            {
                r[pos] = (r[pos] - r[ipos] * p[pos - ipos]) % MOD;
            }
        }
        
        if (r[m] < 0)
        {
            r[m] += MOD;
        }
        cout << r[m] << endl;
    }
    
    return 0;
}

