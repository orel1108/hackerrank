#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_SIZE 128
#define MAX_SUM 2048
#define MOD 1000000007

int main()
{
    int m, r, s;
    int sa, sb;
    long long res = 0;

    cin >> m >> r >> s;
    
    sa = (r + s) / 2;
    sb = (r - s) / 2;
    
    if (sb >= 0)
    {
        vector<long long> a(m);
        for (int pos = 0; pos < m; ++pos)
        {
            cin >> a[pos];   
        }

        vector<vector<long long>> dp(MAX_SIZE, vector<long long>(MAX_SUM));
        dp[0][0] = 1;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = m; j >= 1; j--)
            {
                for (int k = 2000; k >= 0; k--)
                {
                    if (k >= a[i])
                    {
                        dp[j][k] = (dp[j][k] + dp[j - 1][k - a[i]]) % MOD;   
                    }
                }
            }
        }

        for (int i = 1; i < m + 1; i++)
        {
            res = (res + (dp[i][sa] * dp[i][sb]) % MOD) % MOD;   
        }
    }
    
    cout << res << endl;
    return 0;
}

