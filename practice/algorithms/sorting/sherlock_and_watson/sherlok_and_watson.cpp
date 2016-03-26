#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, q, x;
    cin >> n >> k >> q;
    
    k = k % n;
    
    vector<int> arr(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> arr[pos];    
    }
    
    while (q--)
    {
        cin >> x;
        cout << arr[(x + n - k) % n] << endl;
    }
    
    return 0;
}

