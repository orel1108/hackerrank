#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while (t--)
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
        long long res = 0;
        while (cnt < n)
        {
            long long ecnt = 1;
            while ((cnt + ecnt) < n && (arr[cnt] == arr[cnt + ecnt]))
            {
                ecnt++;
            }
            cnt += ecnt;
            res += ecnt * (ecnt - 1);
        }
        
        cout << res << endl;
    }
    
    return 0;
}

