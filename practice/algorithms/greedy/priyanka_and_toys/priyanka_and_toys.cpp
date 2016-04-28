#include <cmath>
#include <cstdio>
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
    sort(arr.begin(), arr.end());
    
    int cnt = 0;
    int res = 0;
    while (cnt < n)
    {
        int in_cnt = 0;
        res += 1;
        while (cnt + in_cnt < n && arr[cnt + in_cnt] - arr[cnt] <= 4)
        {
            in_cnt++;
        }
        cnt += in_cnt;
    }
    
    cout << res << endl;
    
    return 0;
}

