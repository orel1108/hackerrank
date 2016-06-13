#include <iostream>

using namespace std;

unsigned long long count(unsigned long long i_p, unsigned long long i_n)
{
    if (i_n < i_p)
    {
        return 0;
    }
    
    unsigned long long d = i_n / i_p;
    return d + count(i_p, d);
}

unsigned long long bsearch(unsigned long long i_n)
{
    unsigned long long left = 0, right = 5 * i_n;
    while (right - left > 1)
    {
        unsigned long long mid = left + (right - left) / 2;
        if (count(5, mid) < i_n)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    return right;
}

int main()
{
    int t;
    unsigned long long n;
    
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << bsearch(n) << endl;
    }
    
    return 0;
}

