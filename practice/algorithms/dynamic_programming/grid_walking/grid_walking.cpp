#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <tuple>

using namespace std;

const long long MOD = 1000000007;

map<pair<long long, long long>, long long> CVAL;

map<tuple<long long, long long, long long>, long long> WAYS;

long long num_ways_1d_util(long long i_pos, long long i_d, long long i_m)
{
    if (WAYS.find(make_tuple(i_pos, i_d, i_m)) != WAYS.end())
    {
        return WAYS[make_tuple(i_pos, i_d, i_m)];
    }
    
    if (i_pos < 1LL || i_pos > i_d)
    {
        return 0LL;
    }

    if (i_m == 0LL)
    {
        return 1LL;   
    }
    
    long long res = num_ways_1d_util(i_pos - 1, i_d, i_m - 1) + num_ways_1d_util(i_pos + 1, i_d, i_m - 1);
    WAYS[make_tuple(i_pos, i_d, i_m)] = res % MOD;
    
    return res % MOD;
}

map<long long, long long> num_ways_1d(long long i_pos, long long i_d, long long i_m)
{
    map<long long, long long> res;
    for (long long M = 0LL; M < i_m + 1; ++M)
    {
        res[M] = num_ways_1d_util(i_pos, i_d, M);
    }
    
    return res;
}

vector<map<long long, long long>> num_ways_1d_ind(vector<long long> i_x, vector<long long> i_d, long long i_m, long long i_n)
{
    vector<map<long long, long long>> res;
    for (long long pos = 0LL; pos < i_n; ++pos)
    {
        res.push_back(num_ways_1d(i_x[pos], i_d[pos], i_m));
    }
    return res;
}

long long fact_mod(long long i_n, long long i_m)
{
    long long res = 1LL;
    for (long long val = 2LL; val < i_n + 1; ++val)
    {
        res *= val;
        if (res >= i_m)
        {
            res %= i_m;
        }
    }
    
    return res;
}

long long pow_mod(long long i_v, long long i_n, long long i_m)
{
    long long res = 1LL;
    while (i_n > 0LL)
    {
        if (i_n & 1LL == 1LL)
        {
            res *= i_v;
            if (res >= i_m)
            {
                res %= i_m;
            }
        }
        
        i_v *= i_v;
        
        if (i_v >= i_m)
        {
            i_v %= i_m;
        }
        
        i_n /= 2;
    }
    
    return res;
}

long long cnk(long long i_n, long long i_k)
{
    if (CVAL.find(make_pair(i_n, i_k)) != CVAL.end())
    {
        return CVAL[make_pair(i_n, i_k)];
    }
    
    long long num = fact_mod(i_n, MOD);
    long long den = fact_mod(i_n - i_k, MOD) * fact_mod(i_k, MOD) % MOD;
    
    long long res = num * pow_mod(den, MOD - 2, MOD);
    
    CVAL[make_pair(i_n, i_k)] = res % MOD;
    
    return res % MOD;
}

long long solve(vector<long long> i_x, vector<long long> i_d, long long i_m, long long i_n)
{
    vector<map<long long, long long>> ind = num_ways_1d_ind(i_x, i_d, i_m, i_n);
    vector<vector<long long>> f(i_n, vector<long long>(i_m + 1));
    
    for (long long M = 0LL; M < i_m + 1; ++M)
    {
        f[0][M] = ind[0][M];
    }
    
    for (long long J = 1LL; J < i_n; ++J)
    {
        for (long long K = 0LL; K < i_m + 1; ++K)
        {
            for (long long I = 0LL; I < K + 1; ++I)
            {
                long long tmp = cnk(K, I) * f[J - 1][I] % MOD;
                f[J][K] += tmp * ind[J][K - I] % MOD;
                if (f[J][K] >= MOD)
                {
                    f[J][K] %= MOD;
                }
            }
        }
    }
    
    return f[i_n - 1][i_m] % MOD;
}

int main()
{
    int t, n, m;
    cin >> t;
    
    while (t--)
    {
        cin >> n >> m;
        
        vector<long long> x(n);
        for (long long pos = 0; pos < n; ++pos)
        {
            cin >> x[pos];
        }
        
        vector<long long> d(n);
        for (long long pos = 0; pos < n; ++pos)
        {
            cin >> d[pos];
        }
        
        long long ans = solve(x, d, m, n);
        
        cout << ans << endl;
    }
    
    return 0;
}

