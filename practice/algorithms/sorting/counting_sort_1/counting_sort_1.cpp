#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    map<int, int> counter;
    for (int i = 0; i < 100; i++)
    {
        counter.insert(make_pair(i, 0));
    }
    
    int n, v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        counter[v]++;
    }
    
    for (int i = 0; i < 100; i++)
    {
        cout << counter[i] << " ";
    }
    
    return 0;
}

