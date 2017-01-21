#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int i_a, int i_b)
{
    int c;
    while (i_a != 0)
    {
        c = i_a; 
        i_a = i_b % i_a;
        i_b = c;
    }
    return i_b;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int pos = 0; pos < n; ++pos)
    {
       cin >> a[pos];
    }
    
    int g = accumulate(a.begin(), a.end(), a[0], 
                       [](int i_a, int i_b)
                      {
                          return gcd(i_a, i_b);
                      });
    
    int ans = 0, x = 2;
    while (x  * x < g + 1)
    {
        if (g % x == 0)
        {
            ans = max(ans, k - k % x);
            ans = max(ans, k - k % (g / x));
        }
        x++;
    }
    ans = max(ans, k - k % g);
    cout << ans << endl;
    
    return 0;
}

