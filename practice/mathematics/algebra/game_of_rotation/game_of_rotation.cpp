#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int n;
    long long s, s1, sk, part_sum, res;
    
    cin >> n;
    
    vector<long long> arr(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> arr[pos];    
    }
    
    s = accumulate(arr.begin(), arr.end(), 0.0);
    
    s1 = 0;
    for (int pos = 0; pos < n; ++pos)
    {
        s1 += (pos + 1) * arr[pos];
    }
    
    part_sum = arr[0];
    res = s1;
    for (int k = 2; k < n + 1; ++k)
    {
        sk = s1 - (k - 1) * s + n * part_sum;
        part_sum += arr[k - 1];
        if (sk > res)
        {
            res = sk;
        }
    }
    
    cout << res << endl;
    
    return 0;
}

