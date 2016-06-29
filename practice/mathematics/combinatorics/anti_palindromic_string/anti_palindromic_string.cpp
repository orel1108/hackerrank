#include <iostream>

using namespace std;

const unsigned long long MOD = 1000000007;

unsigned long long pow_mod(unsigned long long i_m, unsigned long long i_n)
{
    unsigned long long res = 1;
    while (i_n > 0)
    {
        if (i_n & 0x1)
        {
            res *= i_m;
            if (res >= MOD)
            {
                res %= MOD;   
            }
        }
        
        i_m *= i_m;
        if (i_m >= MOD)
        {
            i_m %= MOD;   
        }
        
        i_n >>= 1;
    }
    return res;
}

int main()
{
    int t;
    unsigned long long n, m;
    
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        if (n == 1)
        {
            cout << m << endl;    
        }
        else if (n == 2)
        {
            cout << (m * (m - 1) % MOD) << endl;   
        }
        else
        {
            unsigned long long total = pow_mod(m - 2, n - 2);
            unsigned long long res = total * m;
            if (res > MOD)
            {
                res %= MOD;   
            }
            res *= (m - 1);
            cout << (res % MOD) << endl;   
        }
    }
    
    return 0;
}

