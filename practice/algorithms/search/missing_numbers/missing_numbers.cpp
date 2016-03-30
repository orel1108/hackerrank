#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, v;
    
    cin >> n;
    vector<int> seqA(10000);
    for (int pos = 0; pos < n; ++pos)
    {
        cin >> v;
        seqA[v] += 1;
    }
    
    cin >> m;
    vector<int> seqB(10000);
    for (int pos = 0; pos < m; ++pos)
    {
        cin >> v;
        seqB[v] += 1;
    }
    
    for (int pos = 0; pos < 10000; ++pos)
    {
        if (seqB[pos] > seqA[pos])
        {
            printf("%d ", pos);
        }
    }
    
    return 0;
}

