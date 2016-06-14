#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

unsigned long long count_2(unsigned long long i_n)
{
    unsigned long long cnt = 0;
    while (i_n > 0 && (i_n % 2 == 0))
    {
        cnt++;
        i_n /= 2;
    }
    
    return cnt;
}

unsigned long long count_5(unsigned long long i_n)
{
    unsigned long long cnt = 0;
    while (i_n > 0 && (i_n % 5 == 0))
    {
        cnt++;
        i_n /= 5;
    }
    
    return cnt;
}

int main()
{
    int t;
    unsigned long long x, c2, c5, m;
    unsigned long long d, n, r, a;
    
    cin >> t;
    while (t--)
    {
        cin >> x;
        c2 = count_2(x);
        c5 = count_5(x);
        if (c2 > 2)
        {
            m = max(c2 - 2, c5);
        }
        else
        {
            m = c5;
        }
        
        d = pow(2, c2) * pow(5, c5);
        x /= d;
        
        r = 1;
        a = 1;
        while (a % x != 0)
        {
            a = (10 * a + 1) % x;
            r++;
        }
        
        cout << 2 * r + m << endl;
    }
    
    return 0;
}

