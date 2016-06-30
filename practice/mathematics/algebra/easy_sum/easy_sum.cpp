#include <iostream>

using namespace std;

int main()
{
    int t;
    unsigned long long n, m, q, r, res;
    
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        q = n / m;
        r = n - q * m;
        
        res = m * (m - 1) / 2;
        res *= q;
        res += r * (r + 1) / 2;
        
        cout << res << endl;
    }

    return 0;
}

