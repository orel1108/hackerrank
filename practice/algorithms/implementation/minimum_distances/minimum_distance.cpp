#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, a;
    cin >> n;
    
    map<int, set<int>> positions;
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> a;
        positions[a].insert(pos);
    }
    
    int res = n;
    map<int, set<int>>::const_iterator it = positions.begin();
    for (; it != positions.end(); ++it)
    {
        if (it->second.size() > 1)
            res = min(res, *(it->second.rbegin()) - *(it->second.begin()));
    }
    
    if (res < n)
    {
        cout << res << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    
    return 0;
}

