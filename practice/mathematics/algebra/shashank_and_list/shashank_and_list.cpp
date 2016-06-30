#include <iostream>

using namespace std;

const unsigned MOD = 1000000007;

unsigned long long pow_mod(unsigned long long i_deg) 
{
    unsigned long long res = 1;
    unsigned long long a = 2;
    while (i_deg)
    {
        if (i_deg & 0x01)
        {
            res *= a;
            res %= MOD;
        }
        
        a *= a;
        a %= MOD;
        
        i_deg >>= 1;
    }
    
    return res % MOD;
}

int main()
{
    unsigned n, i;
    unsigned long long deg, val, res = 1;
    
    cin >> n;
    while (n--)
    {
        cin >> deg;
        val = pow_mod(deg);
        res *= (1 + val);
        if (res >= MOD)
        {
            res %= MOD;   
        }
    }
    
    cout << res - 1 << endl;
}

