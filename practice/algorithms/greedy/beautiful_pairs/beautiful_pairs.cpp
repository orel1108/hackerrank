#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> a[pos];
    }
    
    vector<int> b(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> b[pos];
    }
    
    set<int> x;
    set<int> y;
    
    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < n; ++c)
        {
            if (a[r] == b[c])
            {
                if (x.find(r) == x.end() && y.find(c) == y.end())
                {
                    x.insert(r);
                    y.insert(c);
                }
            }
        }
    }
    
    if (n == 1)
    {
        cout << 0 << endl;
    }
    else if (x.size() == n)
    {
        cout << (n - 1) << endl;
    }
    else
    {
        cout << (x.size() + 1) << endl;
    }
    
    return 0;
}

