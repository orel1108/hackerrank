#include <iostream>

using namespace std;

unsigned long long pow_mod(unsigned long long i_a, unsigned long long i_deg, unsigned long long i_mod)
{
    unsigned long long res = 1;
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
        
        i_deg >>= 1;
    }
    
    return res;
}

int main()
{
    int t;
    unsigned long long n, m, d;
    
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        d = pow_mod(10, n, 9 * m);
        if (d > 0)
        {
            d--;
        }
        else
        {
            d = 9 * m - 1;
        }
        
        d /= 9;
        cout << d << endl;
    }
    
    return 0;
}

