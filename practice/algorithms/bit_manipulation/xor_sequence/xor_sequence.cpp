#include <iostream>

using namespace std;

long long xor_range(long long i_n)
{
    int r = (i_n % 8) / 2;
    if (r == 0)
    {
        return i_n;
    }
    else if (r == 1)
    {
        return 2LL;
    }
    else if (r == 2)
    {
        return i_n + 2;
    }
    
    return 0LL;
}

int main()
{
    int q;
    long long l, r;
    
    cin >> q;
    while (q--)
    {
        cin >> l >> r;
        long long res = xor_range(r) ^ xor_range(l - 1);
        cout << res << endl;
    }
    
    return 0;
}

