#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    set< int > s;
    int q, x, y;
    
    cin >> q;
    while(q--)
    {
        cin >> y >> x;
        if (y == 1)
        {
            s.insert(x);
        }
        else if (y == 2)
        {
            if (s.find(x) != s.end())
            {
                s.erase(x);
            }
        }
        else
        {
            if (s.find(x) != s.end())
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }
    return 0;
}

