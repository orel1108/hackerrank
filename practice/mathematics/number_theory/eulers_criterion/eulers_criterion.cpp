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

bool euler(unsigned long long i_a, unsigned long long i_p)
{
    unsigned long long x = pow_mod(i_a, (i_p - 1) / 2, i_p);
    if (x == 1)
    {
        return true;
    }
    return false;
}

int main()
{
    int t;
    unsigned long long a, p;
    
    cin >> t;
    while (t--)
    {
        cin >> a >> p;
        if (p == 2 || a == 0 || euler(a, p))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}

