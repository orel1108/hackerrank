#include <iostream>

using namespace std;

int main()
{
    int t;
    long long n;
    
    cin >> t;
    while (t--)
    {
        cin >> n;
        long long ans = n * (n - 1) / 2;
        cout << ans << endl;
    }
    return 0;
}

