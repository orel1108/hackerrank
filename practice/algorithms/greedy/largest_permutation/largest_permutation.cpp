#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> p(n + 1);
    vector<int> d(n + 1);
    for (int pos = 1; pos < n + 1; ++pos)
    {
        cin >> p[pos];
        d[p[pos]] = pos;
    }
    
    int cnt = 1;
    while (cnt < n && k > 0)
    {
        if (p[cnt] != (n - cnt + 1))
        {
            int pos = d[n - cnt + 1];
            d[p[cnt]] = d[n - cnt + 1];
            d[n - cnt + 1] = cnt;
            swap(p[cnt], p[pos]);
            k--;   
        }
        cnt++;
    }
    
    for (int pos = 1; pos < n + 1; ++pos)
    {
        cout << p[pos] << " ";
    }
    cout << endl;
    
    return 0;
}

