#include <iostream>

using namespace std;

int max_xor(int i_l, int i_r)
{
    int maxv = 0;
    for (int i = i_l; i < i_r + 1; ++i)
    {
        for (int j = i_l; j < i; ++j)
        {
            int x = i ^ j;
            if (x > maxv)
            {
                maxv = x;
            }
        }
    }
    
    return maxv;
}

int main()
{
    int res, l, r;
    cin >> l >> r;
    res = max_xor(l, r);
    cout << res << endl;
    
    return 0;
}

