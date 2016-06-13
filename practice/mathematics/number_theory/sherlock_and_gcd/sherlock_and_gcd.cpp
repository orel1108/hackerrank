#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t, n;
    
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> a(n);
        for (int pos = 0; pos < n; ++pos)
        {
            cin >> a[pos];
        }
        
        int m = *min_element(a.begin(), a.end());
        if (m == 1)
        {
            cout << "YES" << endl;   
        }
        else
        {
            int val = 2;
            while (val < m + 1)
            {
                int pos = 0;
                while (pos < n)
                {
                    if (a[pos] % val != 0)
                        break;
                    pos++;
                }
                if (pos == n)
                {
                    cout << "NO" << endl;
                    break;
                }
                val++;
            }
            if (val == m + 1)
            {
                cout << "YES" << endl;   
            }
        }
    }
    
    return 0;
}

