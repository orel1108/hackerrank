#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int solve(vector<unsigned> i_a)
{
    vector<unsigned> c_a = i_a;
    sort(c_a.begin(), c_a.end());
    
    map<unsigned, int> idx;
    for (int pos = 0; pos < i_a.size(); ++pos)
    {
        idx[i_a[pos]] = pos;
    }
    
    int r = 0;
    for (int pos = 0; pos < i_a.size(); ++pos)
    {
        if (i_a[pos] == c_a[pos])
            continue;
        int p = idx[c_a[pos]];
        swap(i_a[pos], i_a[p]);
        idx[i_a[pos]] = pos;
        idx[i_a[p]] = p;
        r++;
    }
    
    return r;
}

int main()
{
    int n;
    cin >> n;
    
    vector<unsigned> a(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> a[pos];
    }
    
    int r1 = solve(a);
    
    reverse(a.begin(), a.end());
    int r2 = solve(a);
    
    cout << min(r1, r2) << endl;
    
    return 0;
}

