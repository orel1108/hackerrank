#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int k = 0;
        while (k <= n)
        {
            if ((n - k) % 3 == 0)
            {
                for (int j = 0; j < n - k; j++)
                {
                    cout << 5;
                }
                for (int j = n - k; j < n; j++)
                {
                    cout << 3;
                }
                break;
            }
            k += 5;
            if (k > n)
            {
                cout << -1;
            }
        }
        cout << endl;
    }

    return 0;
}


