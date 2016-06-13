#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int t;
    long long a, b, x, p, k;
    
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> x;
        p = static_cast<long long>(pow(a, b));
        if (p < x)
        {
            if (2 * p <= x)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << x << endl;
            }
        }
        else
        {
            k = p / x;
            k *= x;
            
            if (2 * p <= 2 * k + x)
            {
                cout << k << endl;
            }
            else
            {
                cout << k + x << endl;
            }
        }
    }
    
    return 0;
}

