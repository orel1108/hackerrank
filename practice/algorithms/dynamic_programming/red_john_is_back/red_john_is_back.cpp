#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long num_var(long long i_n)
{
    if (i_n == 1 || i_n == 2 || i_n == 3)
    {
        return 1LL;
    }
    if (i_n == 4)
    {
        return 2LL;
    }
    
    return num_var(i_n - 1) + num_var(i_n - 4);
}

vector<int> sieve(long long i_n)
{
    vector<int> is_prime(i_n + 1, 1);
    is_prime[0] = 0;
    is_prime[1] = 0;
    
    long long i = 2LL;
    while (i * i <= i_n)
    {
        if (is_prime[i])
        {
            long long j = i * i;
            while (j <= i_n)
            {
                is_prime[j] = 0;
                j += i;
            }
        }
        i++;
    }
    
    return is_prime;
}

int main()
{
    long long mx_num = num_var(40);
    vector<int> prime = sieve(mx_num);
    
    for (long long pos = 0; pos < mx_num; ++pos)
    {
        prime[pos + 1] += prime[pos];
    }
    
    int t;
    long long n;
    cin >> t;
    
    while (t--)
    {
        cin >> n;
        long long num = num_var(n);
        cout << prime[num] << endl;
    }
    return 0;
}

