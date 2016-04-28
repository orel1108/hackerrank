#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>

using namespace std;

long long pow_mod(long long i_val, long long i_pow, long long i_mod)
{
    long long res = 1LL;
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
    const long long MOD = 1000000007;
    
    string v;
    cin >> v;
    
    const int n = v.size();
    
    vector<int> digits;
    transform(v.begin(), v.end(), back_inserter(digits), 
              [](char i_ch)
              {
                  return static_cast<int>(i_ch - '0');
              });
    
    long long s = 0LL;
    long long p = 10LL;
    
    for (int pos = 0; pos < n; ++pos)
    {
        s += (n - pos) * (p - 1) * digits[n - pos - 1];
        p *= 10LL;
        
        p %= MOD;
        s %= MOD;
    }
    
    long long res = (s * pow_mod(9LL, MOD - 2, MOD)) % MOD;
    
    cout << res << endl;
    
    return 0;
}

