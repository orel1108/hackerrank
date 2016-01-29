#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t, n, a, b;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cin >> a;
        cin >> b;
        if (n == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            if (a == b)
            {
                cout << a * (n - 1) << endl;
            }
            else
            {
                if (a > b)
                {
                    swap(a, b);
                }
                for (int j = 0; j < n; j++)
                {
                    int val = a * (n - 1 - j) + b * j;
                    cout << val << " ";
                }
                cout << endl;
            }
        }
        
    }
    return 0;
}
