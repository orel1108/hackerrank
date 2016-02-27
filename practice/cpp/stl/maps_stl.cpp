#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int q, y, type;
    string name;
    map< string, int > marks;
    map< string, int >::iterator it;
    cin >> q;
    while (q--)
    {
        cin >> type;
        cin >> name;
        it = marks.find(name);
        if (type == 1)
        {
            cin >> y;
            if (it != marks.end())
                marks[name] += y;
            else
                marks.insert(make_pair(name, y));
        }
        else if (type == 2)
        {
            if (it != marks.end())
                marks.erase(name);
        }
        else
        {
            if (it != marks.end())
                cout << marks[name] << endl;
            else
                cout << 0 << endl;
        }
    }
    
    return 0;
}

