#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
    int n, v;
    cin >> n;
    string s;
    
    map<int, int> counter;
    for (int i = 0; i < 100; i++)
    {
        counter.insert(make_pair(i, 0));
    }
    
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        cin >>s;
        counter[v]++;
    }
    
    int sum = 0;
    for (int i = 0; i < 100; i++)
    {
        sum += counter[i];
        cout << sum << " ";
    }
    
    return 0;
}

