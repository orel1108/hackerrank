#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, a, res = 0;
    vector<int> counter(k);
    
    cin >> n >> k;
    while (n--)
    {
        cin >> a;
        counter[a % k]++;
    }
    
    if (counter[0] > 0)
    {
        res = 1;
    }
    
    for (int pos = 1; pos < k / 2 + 1; ++pos)
    {
        res += max(counter[pos], counter[k - pos]);
    }
    
    if (k % 2 == 0)
    {
        if (counter[k / 2] > 1)
        {
            res -= counter[k / 2] - 1;
        }
    }
    
    cout << res << endl;
    
    return 0;
}

