#include <iostream>

using namespace std;

int main()
{
    int t, n;
    unsigned long long a, cnt1, cnt2, s;
    
    cin >> t;
    while (t--)
    {
        cin >> n;
        cnt1 = cnt2 = 0;
        for (int cnt = 0; cnt < n; ++cnt)
        {
            cin >> a;
            if (a == 1)
            {
                cnt1++;
            }
            else if (a == 2)
            {
                cnt2++;
            }
        }
        
        s = cnt1 * (n - 1) + cnt2 * (cnt2 - 1) / 2;
        cout << s << endl;
    }
    
    return 0;
}

