#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t, n, k;
    
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<int> a;
        for (int cnt = 0; cnt < n / 2; ++cnt)
        {
            a.push_back(n - 1 - cnt);
            a.push_back(cnt);
        }
        a.push_back(n / 2);
        
        int ans = distance(a.begin(), find(a.begin(), a.end(), k));
        cout << ans << endl;
    }
    
    return 0;
}

