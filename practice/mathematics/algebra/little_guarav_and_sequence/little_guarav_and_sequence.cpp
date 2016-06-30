#include <iostream>

using namespace std;

unsigned log_2(unsigned long long i_val)
{
    unsigned res = 0;
    while (i_val > 0)
    {
        res++;
        i_val >>= 1;
    }
    return res - 1;
}

int main()
{
    unsigned t;
    unsigned long long n;
    
    cin >> t;
    while (t--)
    {
        cin >> n;
        unsigned lg = log_2(n);
        
        unsigned rem1 = n % 2 == 0 ? 1 : 5;
        unsigned rem2 = lg == 0 ? 2 : (6 * lg) % 10;
        unsigned res = (rem1 * rem2) % 10;
        cout << res << endl;
    }
    
    return 0;
}
