#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    
    while (t--)
    {
        cin >> n;
        
        vector<int> arr(n);
        for (int pos = 0; pos < n; ++pos)
        {
            cin >> arr[pos];
        }
        
        if (n % 2 == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            int r = 0;
            for (int cnt = 0; cnt < n; cnt += 2)
            {
                r ^= arr[cnt];
            }
            cout << r << endl;
        }
    }
    return 0;
}

