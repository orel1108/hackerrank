#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

pair<vector<long long>, vector<bool>> sieve(long long i_n)
{
    vector<bool> is_prime(i_n + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    long long i = 2;
    while (i * i <= i_n)
    {
        if (is_prime[i])
        {
            long long j = i * i;
            while (j <= i_n)
            {
                is_prime[j] = false;
                j += i;
            }
        }
        i++;
    }
    
    vector<long long> primes;
    for (long long pos = 0; pos < is_prime.size(); ++pos)
    {
        if (is_prime[pos])
        {
            primes.push_back(pos);
        }
    }
    
    return make_pair(primes, is_prime);
}

vector<long long> phi(const vector<long long> & i_primes, const vector<bool> & i_isprime, long long i_n)
{
    vector<long long> res;
    res.push_back(0);
    res.push_back(1);
    
    for (long long val = 2; val < i_n + 1; ++val)
    {
        if (i_isprime[val])
        {
            res.push_back(val - 1);
        }
        else
        {
            vector<long long>::const_iterator cit = i_primes.begin();
            for (; cit != i_primes.end(); ++cit)
            {
                long long p = *cit;
                if (val % p == 0)
                {
                    long long cnt = 0;
                    long long n = val;
                    while (n % p == 0)
                    {
                        cnt++, n /= p;
                    }
                    res.push_back(static_cast<long long>(pow(p, cnt - 1)) * (p - 1) * res[n]);
                    break;
                }
            }
        }
    }
    
    return res;
}

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
    const long long n = 1000000;
    
    pair<vector<long long>, vector<bool>> p = sieve(n);
    
    vector<long long> ph = phi(p.first, p.second, n);
    
    int t;
    long long a, b, x, r, s;
    
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> x;
        if (b >= 0)
        {
            r = pow_mod(a, b, x);
        }
        else
        {
            s = pow_mod(a, ph[x] - 1, x);
            r = pow_mod(s, abs(b), x);
        }
        
        cout << r << endl;
    }
    
    return 0;
}

