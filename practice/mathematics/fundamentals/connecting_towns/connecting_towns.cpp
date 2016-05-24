#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> a(n - 1);
        for (int pos = 0; pos < n - 1; ++pos)
        {
            cin >> a[pos];
        }
        
        cout << accumulate(a.begin(), a.end(), 1, 
                           [](int x, int y)
                          {
                              return (x * y) % 1234567;
                          }) << endl;
    }
    return 0;
}

