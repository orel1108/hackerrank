#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    int L, R, v;
    cin >> n >> m;
    
    vector<long long int> buff(n);
    while (m--)
    {
        cin >> L >> R >> v;
        buff[L - 1] += v;
        if (R < n)
        {
            buff[R] -= v;
        }
    }
    
    long long int d = buff[0];
    long long int r = buff[0];
    for (int pos = 1; pos < n; ++pos)
    {
        d += buff[pos];
        if (d > r)
        {
            r = d;
        }
    }
    
    cout << r << endl;
    
    return 0;
}

