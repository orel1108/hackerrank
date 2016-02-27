#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector< int > v;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i)
    {
        cout << v[i] << " ";    
    }
    return 0;
}

