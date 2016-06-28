#include <vector>
#include <iostream>

using namespace std;

int sum_digits(unsigned i_value)
{
    int res = 0;
    while (i_value > 0)
    {
        res += i_value % 10;
        i_value /= 10;
    }
    return res;
}

vector<unsigned> sieve(unsigned i_n)
{
    vector<bool> is_prime(i_n + 1, true);
    
    unsigned i = 2;
    while (i * i <= i_n)
    {
        if (is_prime[i])
        {
            unsigned j = i * i;
            while (j <= i_n)
            {
                is_prime[j] = false;
                j += i;
            }
        }
        i++;
    }
    
    vector<unsigned> primes;
    for (unsigned val = 2; val < i_n + 1; ++val)
    {
        if (is_prime[val])
        {
            primes.push_back(val);
        }
    }
    
    return primes;
}

int main()
{
    int t, d, s = 0;
    
    unsigned n;
    cin >> n;
    d = sum_digits(n);
    
    vector<unsigned> primes = sieve(10000000);
    
    vector<unsigned>::iterator it = primes.begin();
    for (; it != primes.end(); ++it)
    {
        unsigned p = *it;
        if (n < p)
        {
            break;
        }
        if (n % p == 0)
        {
            t = sum_digits(p);
            while (n % p == 0)
            {
                s += t;
                n /= p;
            }
        }
        if (s > d)
        {
            break;
        }
    }
    
    if (s == d)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    
    return 0;
}

