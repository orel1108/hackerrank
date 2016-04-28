#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
    long long n, k;
    cin >> n >> k;
    
    vector<int> prices(n);
    for(int pos = 0; pos < n; ++pos)
    {
        cin >> prices[pos];
    }
    
    sort(prices.begin(), prices.end());
    
    int cnt = 0;
    int sum = 0;
    while (sum <= k)
    {
        sum += prices[cnt];
        cnt++;
    }
    
    cout << (cnt - 1) << endl;
    
    return 0;
}

