#include <iostream>

using namespace std;

int main()
{
    int n;
    unsigned long long a;
    cin >> n;
    
    unsigned long long res = 1;
    while (n--)
    {
        cin >> a;
        res *= (a + 1);
        res %= 1000000007;
    }
    
    cout << res - 1 << endl;
    
    return 0;
}

