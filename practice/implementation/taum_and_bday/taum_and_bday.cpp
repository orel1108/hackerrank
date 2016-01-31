#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int t;
    long long x, y, z, b, w;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> b >> w >> x >> y >> z;
        if ((x + z) < y)
        {
            cout << x * (b + w) + z * w << endl;
        }
        else if ((y + z) < x)
        {
            cout << y * (b + w) + z * b << endl;
        }
        else
        {
            cout << x * b + y * w << endl;
        }
    }
    return 0;
}

