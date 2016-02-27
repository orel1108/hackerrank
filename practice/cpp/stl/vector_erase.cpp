#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, a;
    vector< int > v;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        v.push_back(a);
    }

    int p1, p2;
    cin >> p1;

    v.erase(v.begin() + p1 - 1);
    cin >> p1 >> p2;

    v.erase(v.begin() + p1 - 1, v.begin() + p2 - 1);
    cout << v.size() << endl;

    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";

    return 0;
}

