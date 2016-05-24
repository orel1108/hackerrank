#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int i_a, int i_b)
{
    if (i_a > i_b)
    {
        swap(i_a, i_b);
    }
    
    while (i_b)
    {
        int c = i_a % i_b;
        i_a = i_b;
        i_b = c;
    }
    
    return i_a;
}

int main()
{
    int t, l, b;
    cin >> t;
    
    while (t--)
    {
        cin >> l >> b;
        int g = gcd(l, b);
        int ans = l * b / (g * g);
        cout << ans << endl;
    }
    return 0;
}

