#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> arr[pos];
    }
    
    int x = accumulate(arr.begin(), arr.end(), 0, [](int s, int t) { return s ^ t; });
    if (x == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        int cnt = 0;
        for (int pos = 0; pos < n; ++pos)
        {
            if ((x ^ arr[pos]) < arr[pos])
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

