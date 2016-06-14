#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

unsigned long long gcd(unsigned long long i_a, unsigned long long i_b)
{
    if (i_a > i_b)
    {
        swap(i_a, i_b);
    }
    
    while (i_a > 0)
    {
        unsigned long long c = i_b % i_a;
        i_b = i_a;
        i_a = c;
    }
    
    return i_b;
}

unsigned long long lcm(unsigned long long i_a, unsigned long long i_b)
{
    return i_a * i_b / gcd(i_a, i_b);
}

int main()
{
    int t;
    int n;
    
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<unsigned> a(n);
        for (int pos = 0; pos < n; ++pos)
        {
            cin >> a[pos];
        }
        
        cout << a[0] << " ";
        for (int pos = 0; pos < n - 1; ++pos)
        {
            cout << lcm(a[pos], a[pos + 1]) << " ";
        }
        cout << a[n - 1] << endl;
    }
    
    return 0;
}

