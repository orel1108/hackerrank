#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long change(int i_n, const vector<int> & i_coins)
{
    vector<long long> ways(i_n + 1);
    ways[0] = 1LL;
    
    vector<int>::const_iterator cit = i_coins.begin();
    for (; cit != i_coins.end(); ++cit)
    {
        for (int cnt = *cit; cnt < i_n + 1; ++cnt)
        {
            ways[cnt] += ways[cnt - *cit];
        }
    }
    
    return ways.back();
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<int> coins(m);
    for (int pos = 0; pos < m; ++pos)
    {
        cin >> coins[pos];
    }
    
    cout << change(n, coins) << endl;
    
    return 0;
}

