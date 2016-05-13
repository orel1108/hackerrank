#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    pair<long long, long long> p;
    vector<pair<long long, long long>> pd;
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> p.first >> p.second;
        pd.push_back(p);
    }
    
    int pos = 0;
    while (pos < n)
    {
        long long tp = 0, td = 0;
        int cnt = 0;
        while ((cnt < n) && (tp >= td))
        {
            tp += pd[(pos + cnt) % n].first;
            td += pd[(pos + cnt) % n].second;
            cnt++;
        }
        if (cnt == n)
        {
            break;
        }
        pos += cnt;
    }
    
    cout << pos << endl;
    
    return 0;
}

