#include <set>
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
        vector<int> perm(n), check;
        set<int> used;
        
        for (int pos = 1; pos < n + 1; ++pos)
        {
            int d = pos - k;
            if (d > 0 && (used.find(d) == used.end()))
            {
                perm[pos - 1] = d;
                used.insert(d);
            }
            else
            {
                perm[pos - 1] = pos + k;
                used.insert(pos + k);
            }
        }
        
        check = perm;
        sort(check.begin(), check.end());
        bool is_valid = true;
        for (int pos = 0; pos < n; ++pos)
        {
            if (check[pos] != (pos + 1))
            {
                is_valid = false;
                break;
            }
        }
        
        if (is_valid)
        {
            for (int pos = 0; pos < n; ++pos)
            {
                cout << perm[pos] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}

