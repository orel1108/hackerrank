#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    
    int v, n;
    cin >> v >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    auto d = distance(a.begin(), find(a.begin(), a.end(), v));
    
    cout << d << endl;
    
    return 0;
}

