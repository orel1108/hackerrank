#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t, a, b, c;
    
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        if (a > b)
        {
            swap(a, b);
        }
        
        if (a == c || b == c)
        {
            cout << "YES" << endl;
        }
        else
        {
            int d = b - a;
            while (d > 0)
            {
                if (d == c)
                {
                    cout << "YES" << endl;
                    break;
                }
                if (d < a)
                {
                    d = b - (a - d);
                }
                else
                {
                    d = d - a;
                }
            }
            if (d == 0)
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}

