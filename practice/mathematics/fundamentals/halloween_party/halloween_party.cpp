#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int t;
    unsigned long long n, h, r;
    
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n == 0 || n == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            h = n / 2;
            if (n % 2 == 0)
            {
                r = static_cast<unsigned long long>(pow(h, 2));
            }
            else
            {
                r = (n + 1) / 2 * h;
            }
            cout << r << endl;
        }
    }
    
    return 0;
}

