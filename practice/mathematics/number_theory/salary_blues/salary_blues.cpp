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

long long normalize(const vector<long long> & i_a)
{
    long long d = i_a[0];
    for (int pos = 1; pos < i_a.size(); ++pos)
    {
        d = gcd(d, i_a[pos]);
        if (d == 1)
        {
            break;
        }
    }
    
    return d;
}

int main()
{
    int n, q;
    long long k = 0, mx = 0, mn = 100000000000001;
    
    cin >> n >> q;
    
    vector<long long> a(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> a[pos];
        
        mx = max(mx, a[pos]);
        mn = min(mn, a[pos]);
    }
    
    if (mn == mx)
    {
        while (q--)
        {
            cin >> k; 
            cout << a[0] + k << endl;
        }
    }
    else
    {
        long long d = normalize(a);
        while (q--)
        {
            cin >> k;
            cout << gcd(d, k) << endl;
        }
    }
    
    return 0;
}

