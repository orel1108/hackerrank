#include <iostream>

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
    long long n;
    
    cin >> t;
    while (t--)
    {
        cin >> n;
        long long res = pow_mod(2, n, 100000) - 1;
        cout << res << endl;
    }
    return 0;
}

