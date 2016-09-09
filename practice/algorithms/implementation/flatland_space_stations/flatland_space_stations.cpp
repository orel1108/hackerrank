#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, res;
    cin >> n >> m;
    vector<int> c(m);
    for (int pos = 0; pos < m; ++pos)
    {
       cin >> c[pos];
    }
    
    sort(c.begin(), c.end());
    
    res = max(c[0], n - 1 - c[m - 1]);
    for (int pos = 1; pos < m; ++pos)
    {
        res = max(res, (c[pos] - c[pos - 1]) / 2);
    }
    
    cout << res << endl;
    
    return 0;
}

