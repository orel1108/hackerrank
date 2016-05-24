#include <iostream>

using namespace std;

int main()
{
    int t;
    unsigned long long n;
    const unsigned MOD = 1000000007;
    
    cin >> t;
    while (t--)
    {
        cin >> n;
        n %= MOD;
        unsigned long long r = (n * n) % MOD;
        
        cout << r << endl;
    }
    return 0;
}

