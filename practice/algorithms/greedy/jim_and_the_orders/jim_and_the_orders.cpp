#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, t, d;
    cin >> n;
    
    vector<pair<int, int>> buff(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> t >> d;
        buff[pos] = make_pair(t + d, pos + 1);
    }
    
    sort(buff.begin(), buff.end());
    
    for (int pos = 0; pos < n; ++pos)
    {
        cout << buff[pos].second << " ";
    }
    cout << endl;
    
    return 0;
}

