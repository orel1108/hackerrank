#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long i_a, long long i_b)
{
    if (i_a > i_b)
    {
        swap(i_a, i_b);
    }
    
    while (i_a > 0)
    {
        long long c = i_b % i_a;
        i_b = i_a;
        i_a = c;
    }
    
    return i_b;
}

long long num_divisors(long long i_n)
{
    long long cnt = 0;
    long long r = static_cast<long long>(sqrt(i_n));
    
    for (long long val = 1; val < r + 1; ++val)
    {
        if (i_n % val == 0)
        {
            cnt += 2;
        }
    }
    
    if (r * r == i_n)
    {
        cnt--;
    }
    
    return cnt - 1;
}

long long even_squares_divs(long long i_n, const vector<long long> & i_squares)
{
    long long cnt = 0;
    
    vector<long long>::const_iterator cit = i_squares.begin();
    for (; cit != i_squares.end(); ++cit)
    {
        if (*cit >= i_n)
        {
            break;
        }
        if (i_n % *cit == 0)
        {
            cnt++;
        }
    }
    
    return cnt;
}

int main()
{
    int t;
    long long n, ne, nd, d;
    
    vector<long long> squares;
    for (long long x = 2; x < 1001; x += 2)
    {
        squares.push_back(x * x);
    }
    
    cin >> t;
    while (t--)
    {
        cin >> n;
        
        ne = even_squares_divs(n, squares);
        if (ne == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            nd = num_divisors(n);
            d = gcd(nd, ne);
            cout << (ne / d) << "/" << (nd / d) << endl;
        }
    }
    
    return 0;
}

