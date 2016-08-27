#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n, k, r = 0;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int pos = 0; pos < n; ++pos)
    {
       cin >> a[pos];
    }
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if ((a[i] + a[j]) % k == 0)
            {
                r++;
            }
        }
    }
    
    cout << r << endl;
    
    return 0;
}

