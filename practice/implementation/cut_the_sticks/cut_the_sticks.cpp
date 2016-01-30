#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int n, i, cnt, k;
    cin >> n;
    
    vector<int> vals(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vals[i];    
    }
    sort(vals.begin(), vals.end());
    
    cout << n << endl;
    i = cnt = 0;
    while ((cnt + i) < vals.size())
    {
        if (vals[cnt] == vals[cnt + i])
        {
            i++;
        }
        else
        {
            cout << (n - (cnt + i)) << endl;
            cnt += i;
            i = 0;
        }
    }
    return 0;
}

