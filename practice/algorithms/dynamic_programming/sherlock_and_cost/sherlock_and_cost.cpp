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
        vector<int> b(n);
        for (int pos = 0; pos < n; ++pos)
        {
            cin >> b[pos];
        }
        
        int s1 = 0, s2 = 0;
        vector<int> b1(n);
        vector<int> b2(n);
        
        for (int pos = 1; pos < n; ++pos)
        {
            s1 = max(abs(1 - b[pos - 1]) + b2[pos - 1], b1[pos - 1]);
            s2 = max(abs(b[pos] - 1) + b1[pos - 1], abs(b[pos] - b[pos - 1]) + b2[pos - 1]);
            b1[pos] = s1;
            b2[pos] = s2;
        }
        
        cout << max(s1, s2) << endl;
    }
    return 0;
}

