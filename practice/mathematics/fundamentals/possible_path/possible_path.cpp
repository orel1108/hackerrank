#include <iostream>
#include <algorithm>

using namespace std;

unsigned long long gcd(unsigned long long i_a, unsigned long long i_b)
{
    if(i_a < i_b)
    {
        swap(i_a, i_b);
    }
    
    while(i_b > 0)
    {
        unsigned long long c = i_a % i_b;
        i_a = i_b;
        i_b = c;
    }
    
    return i_a;
}

int main()
{
    int t;
    unsigned long long a, b, x, y;
    
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> x >> y;
        unsigned long long t = gcd(a, b);
        unsigned long long s = gcd(x, y);
        if (s == t)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}

