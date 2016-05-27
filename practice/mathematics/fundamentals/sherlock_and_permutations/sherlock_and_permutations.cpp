#include <iostream>

using namespace std;

long long fact_mod(long long i_n, long long i_mod)
{
    long long res = 1;
    for (long long n = 2; n < i_n + 1; ++n)
    {
        res *= n;
        if (res >= i_mod)
        {
            res %= i_mod;
        }
    }
    
    return res;
}

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

long long coeff(long long i_n, long long i_k, long long i_mod)
{
    if (i_k == 0)
    {
        return 1LL;
    }
    
    long long num = fact_mod(i_n, i_mod);
    long long den = fact_mod(i_n - i_k, i_mod) * fact_mod(i_k, i_mod) % i_mod;
    long long iden = pow_mod(den, i_mod - 2, i_mod);
    
    return num * iden % i_mod;
}

int main()
{
    int t;
    long long n, k, r;
    
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        r = coeff(n + k - 1, k - 1, 1000000007);
        
        cout << r << endl;
    }
    return 0;
}

