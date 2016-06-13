#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

long long pow_mod(long long i_value, long long i_deg, long long i_mod)
{
    long long res = 1;
    while (i_deg > 0)
    {
        if (i_deg & 1 == 1)
        {
            res *= i_value;
            if (res >= i_mod)
            {
                res %= i_mod;
            }
        }
        
        i_value *= i_value;
        if (i_value >= i_mod)
        {
            i_value %= i_mod;
        }
        
        i_deg /= 2;
    }
    
    return res;
}

long long inverse_mod(long long i_value, long long i_prime)
{
    return pow_mod(i_value, i_prime - 2, i_prime);
}

long long crt(const vector<long long> & i_a, const vector<long long> & i_primes)
{
    long long n = accumulate(i_primes.begin(), i_primes.end(), 1, 
                            [](long long x, long long y)
                            {
                                return x * y;
                            });
    long long x = 0;
    for (int pos = 0; pos < i_primes.size(); ++pos)
    {
        long long d = n / i_primes[pos];
        long long s = i_a[pos] * d * inverse_mod(d, i_primes[pos]);
        x += s;
        if (x >= n)
        {
            x %= n;
        }
    }
    
    return x;
}

vector<long long> decompose(long long i_value, long long i_prime)
{
    vector<long long> coeffs;
    while (i_value > 0)
    {
        coeffs.push_back(i_value % i_prime);
        i_value /= i_prime;
    }
    return coeffs;
}

long long binom_mod(long long i_n, long long i_m, long long i_prime)
{
    if (i_n < i_m)
    {
        return 0;
    }
    if (i_m == 0)
    {
        return 1;
    }
    if (i_m == i_n)
    {
        return 1;
    }
    
    long long num = 1, den = 1;
    for (long long x = 0; x < i_n - i_m; ++x)
    {
        num *= i_n - x;
        den *= i_n - i_m - x;
        if (num >= i_prime)
        {
            num %= i_prime;
        }
        if (den >= i_prime)
        {
            den %= i_prime;
        }
    }
    
    num *= inverse_mod(den, i_prime);
    return num % i_prime;
}

long long lucas(long long i_n, long long i_m, long long i_prime)
{
    vector<long long> n_coeffs = decompose(i_n, i_prime);
    vector<long long> m_coeffs = decompose(i_m, i_prime);
    
    int diff = n_coeffs.size() - m_coeffs.size();
    if (diff > 0)
    {
        while (diff-- > 0)
        {
            m_coeffs.push_back(0);
        }
    }
    
    long long res = 1;
    for (int pos = 0; pos < n_coeffs.size(); ++pos)
    {
        res *= binom_mod(n_coeffs[pos], m_coeffs[pos], i_prime);
        if (res >= i_prime)
        {
            res %= i_prime;
        }
    }
    
    return res;
}

int main()
{
    int t;
    long long n, r, m;
    
    vector<long long> SMALL_PRIMES = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    
    cin >> t;
    while (t--)
    {
        cin >> n >> r >> m;
        
        vector<long long> a, p;
        for (int pos = 0; pos < SMALL_PRIMES.size(); ++pos)
        {
            if ((m % SMALL_PRIMES[pos]) == 0)
            {
                long long v = lucas(n, r, SMALL_PRIMES[pos]);
                a.push_back(v);
                p.push_back(SMALL_PRIMES[pos]);
            }
        }
        
        long long res = crt(a, p);
        cout << res << endl;
    }
    
    return 0;
}

