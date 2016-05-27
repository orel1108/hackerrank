#include <iostream>

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

int main()
{
    int t;
    long long x1, x2, y1, y2, t1, t2, d;
    
    cin >> t;
    while (t--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2)
        {
            if (y1 == y2)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << (abs(y1 - y2) - 1) << endl;
            }
        }
        else if (y1 == y2)
        {
            cout << (abs(x1 - x2) - 1) << endl;
        }
        else
        {
            t1 = abs(x1 - x2);
            t2 = abs(y1 - y2);
            d = gcd(t1, t2);
            t1 /= d;
            if (x1 > x2)
            {
                swap(x1, x2);
            }
            cout << (x2 - x1 - 1) / t1 << endl;
        }
    }
    
    return 0;
}

