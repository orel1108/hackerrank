#include <cmath>
#include <iostream>
#include <set>

using namespace std;

int solve(long long i_d, long long i_p)
{
    long long D = i_d * i_d + 4 * i_p;
    if (D < 0)
    {
        return 0;   
    }
    long long x = static_cast<long long>(sqrt(D));
    if (x * x != D)
    {
        return 0;
    }
    
    pair<long long, long long> coeff[4] = {make_pair(-1, -1), make_pair(-1, 1), make_pair(1, -1), make_pair(1, 1)};
    set<pair<long long, long long>> r;
    for (int pos = 0; pos < 4; ++pos)
    {
        long long c0 = coeff[pos].first;
        long long c1 = coeff[pos].second;
        long long b = (c0 * i_d + c1 * x) / 2;
        long long a = b - c0 * i_d;
        r.insert(make_pair(a, b));
    }
    
    return r.size();
}

int main()
{
    int t;
    long long d, p;
    
    cin >> t;
    while (t--)
    {
        cin >> d >> p;
        if (d < 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << solve(d, p) << endl;   
        }
    }
    
    return 0;
}

