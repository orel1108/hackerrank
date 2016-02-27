#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, q, y, a;
    vector< int > v;
    vector< int >::iterator it;
    
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        v.push_back(a);
    }
    
    cin >> q;
    while (q--)
    {
        cin >> y;
        it = lower_bound(v.begin(), v.end(), y);
        if (y == *it)
        {
            cout << "Yes ";
        }
        else
        {
            cout << "No ";
        }
        cout << (distance(v.begin(), it) + 1) << endl; 
    }
    
    return 0;
}

