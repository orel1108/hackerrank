#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int used_edges(int i_n, int i_k)
{
    int g1 = i_n % i_k;
    int g2 = i_k - g1;
    int s1 = i_n / i_k + 1;
    int s2 = s1 - 1;
    int prod1 = g1 * s1;
    int prod2 = g2 * s2;
    int result = ((prod1 + prod2) * (prod1 + prod2) - (prod1 * s1 + prod2 * s2)) / 2;
    return result;
}

int main()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        
        int r = 2;
        while ((1.0 - 1.0 / r) * n * n / 2.0 < m)
        {
            r++;
        }
        while (used_edges(n, r) < m)
        {
            r++;
        }
        cout << r << endl;
    }
    return 0;
}

