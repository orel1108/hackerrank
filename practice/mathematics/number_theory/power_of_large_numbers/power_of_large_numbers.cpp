#include <iostream>
#include <string>

using namespace std;

long long pow_mod(long long i_a, long long i_deg, long long i_mod)
{
    long long res = 1;
    while (i_deg > 0)
    {
        if (i_deg & 1 == 1)
        {
            res *= i_a;
            if (res >= i_mod)
            {
                res %= i_mod;   
            }
        }
        
        i_a *= i_a;
        if (i_a >= i_mod)
        {
            i_a %= i_mod;
        }
        
        i_deg /= 2;
    }
    
    return res;
}

int main()
{
    int t;
    string s1, s2;
    
    const long long MOD = 1000000007;
    
    cin >> t;
    while (t--)
    {
        cin >> s1 >> s2;
        
        long long a = 0, b = 0;
        for (int pos = 0; pos < s1.size(); ++pos)
        {
            a = 10 * a + static_cast<long long>(s1[pos] - '0');
            if (a >= MOD)
            {
                a %= MOD;
            }
        }
        for (int pos = 0; pos < s2.size(); ++pos)
        {
            b = 10 * b + static_cast<long long>(s2[pos] - '0');
            if (b >= (MOD - 1))
            {
                b %= MOD - 1;
            }
        }
        
        long long res = pow_mod(a, b, MOD);
        cout << res << endl;
    }
    
    return 0;
}

