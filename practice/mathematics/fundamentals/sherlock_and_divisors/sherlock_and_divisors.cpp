#include <cmath>
#include <iostream>

using namespace std;

long long num_divisors(long long i_n)
{
    long long res = 0;
    long long sn = static_cast<long long>(sqrt(i_n));
    for (int d = 1; d < sn + 1; ++d)
    {
        if (i_n % d == 0)
        {
            res += 2;
        }
    }
    if (sn * sn == i_n)
    {
        res--;
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
        if (n % 2 == 0)
        {
            n /= 2;
            cout << num_divisors(n) << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}

