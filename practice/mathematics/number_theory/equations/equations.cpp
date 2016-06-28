#include <vector>
#include <iostream>

using namespace std;

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
    int n;
    cin >> n;
    
    vector<unsigned> primes = sieve(1000000);
    
    int res = 1;
    vector<unsigned>::iterator it = primes.begin();
    for (; it != primes.end(); ++it)
    {
        unsigned long long p = *it;
        unsigned long long s = 0;
        while (n / p > 0)
        {
            s = (s + n / p) % 1000007;
            p *= *it;
        }
        res = (res * (2 * s + 1)) % 1000007;
    }
    
    cout << res << endl;
    
    return 0;
}

