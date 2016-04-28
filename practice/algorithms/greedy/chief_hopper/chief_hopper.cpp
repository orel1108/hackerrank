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
    
    vector<long long> h(n);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> h[pos];
    }
    
    long long s = h[n - 1] / 2 + h[n - 1] % 2;
    for (int pos = n - 2; pos >= 0; pos--)
    {
        s = (h[pos] + s) / 2 + (h[pos] + s) % 2;
    }
    
    cout << s << endl;
    
    return 0;
}

