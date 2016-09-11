#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n, res = 0;
    cin >> n;
    vector<int> b(n);
    for (int pos = 0; pos < n; ++pos)
    {
       cin >> b[pos];
    }
    
    for (int pos = 0; pos < n - 1; ++pos)
    {
        if (b[pos] % 2 == 1)
        {
            b[pos + 1]++;
            res += 2;
        }
    }
    
    if (b[n - 1] % 2 == 0)
    {
        cout << res << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
    return 0;
}

